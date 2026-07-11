class DisjointSet {
public:
    vector<int> rank, size, parent;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n + 1);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            ds.UnionBySize(u, v);
        }
        vector<int> nodeCount(n, 0);
        vector<int> edgeCount(n, 0);
        for(int i =0; i < n; i++){
            int parent = ds.findUpar(i);
            nodeCount[parent]++;
        }
        for(auto it : edges){
            int p = ds.findUpar(it[0]);
            edgeCount[p]++;
        }
        int cntC = 0;
        for(int i = 0; i < n; i++){
            if(ds.findUpar(i) != i){
                continue;
            }

            int node = nodeCount[i];
            int requiredEdge = node * (node - 1) / 2;
            if(requiredEdge == edgeCount[i]){
                cntC++;
            }
        }
    
        return cntC;
    }
};