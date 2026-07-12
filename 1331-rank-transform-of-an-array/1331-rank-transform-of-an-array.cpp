class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        map<int, int> rank;
        int currank = 1;
        for(int it : sorted){
            if(rank.count(it) != 1){
                rank[it] = currank;
                currank++;
            }
        }
          

        for(int i = 0; i < n; i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};