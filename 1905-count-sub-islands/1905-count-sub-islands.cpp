class Solution {
public:
    bool bfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        int m = grid1.size();
        int n = grid1[0].size();
        vis[row][col] = 1;
        bool ok = true;
        queue<pair <int, int>> q;
        q.push({row, col});
        if(grid1[row][col] == 0) ok = false;

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid2[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    if(grid1[nrow][ncol] == 0) ok = false;
                    q.push({nrow, ncol});
                }
            }
        }
        return ok;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid2[i][j] == 1) {
                    if(bfs(i, j, grid1, grid2, vis)) {
                        cnt++;;
                    }
                }
            }
        }
        return cnt;
    }
};