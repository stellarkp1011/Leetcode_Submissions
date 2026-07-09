class Solution {
public:
    // int path(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp){
    //     if(i == n - 1) return triangle[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int down = triangle[i][j] + path(i+1, j, triangle, n, dp);
    //     int dg = triangle[i][j] + path(i + 1, j + 1, triangle, n, dp);
    //     return dp[i][j] = min(down, dg);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return path(0, 0, triangle, n, dp);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     for(int i = 0; i < n; i++){
    //         dp[n - 1][i] = triangle[n - 1][i];
    //     }
    //     for(int i = n - 2; i >= 0; i--){
    //         for(int j = i; j >= 0; j--){
    //                 int down = triangle[i][j] + dp[i + 1][j];
    //                 int dg = triangle[i][j] + dp[i + 1][j + 1];
    //                 dp[i][j] = min(down, dg);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);
        for(int i = 0; i < n; i++){
            front[i] = triangle[n - 1][i];
        }
        for(int i = n - 2; i >= 0; i--){
            vector<int> cur(n, 0);
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j + 1];
                cur[j] = min(down, dg);
            }
            front = cur;
        }
        return front[0];
    }
};