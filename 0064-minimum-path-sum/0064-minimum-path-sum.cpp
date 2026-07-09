class Solution {
public:
//     int path(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//         if(i == 0 && j == 0) return grid[i][j];
//         if(i < 0 || j < 0) return 1e9;
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = grid[i][j] + path(i - 1, j, grid, dp);
//         int left = grid[i][j] + path(i, j - 1, grid, dp);
//         return dp[i][j] = min(up, left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return path(m - 1, n - 1, grid, dp);
//     }
        // int minPathSum(vector<vector<int>>& grid){
        //     int m = grid.size();
        //     int n = grid[0].size();
        //     vector<vector<int>> dp(m, vector<int>(n, 0));
        //     for(int i = 0; i < m; i++){
        //         for(int j = 0; j < n; j ++){
        //             if(i == 0 && j == 0) dp[i][j] = grid[i][j];
        //             else {
        //                 int up = 1e9, left = 1e9;
        //                 if(i > 0) up = grid[i][j] + dp[i - 1][j];
        //                 if(j > 0) left = grid[i][j] + dp[i][j - 1];
        //                 dp[i][j] = min(left, up); 
        //             }
        //         }
        //     }
        //     return dp[m-1][n-1];
        // }
        int minPathSum(vector<vector<int>>& grid){
            int m = grid.size();
            int n = grid[0].size();
            vector<int> prev(n, 1e9);
            for(int i = 0; i < m; i++){
                vector<int> cur(n, 1e9);
                for(int j = 0; j < n; j ++){
                    if(i == 0 && j == 0) cur[j] = grid[i][j];
                    else {
                        int up = grid[i][j];
                        if(i > 0) up += prev[j];
                        else up = 1e9;
                        int left = grid[i][j];
                        if(j > 0) left += cur[j - 1];
                        else left = 1e9;
                        cur[j] = min(left, up); 
                    }
                }
                prev = cur;
            }
            return prev[n-1];
        }
};