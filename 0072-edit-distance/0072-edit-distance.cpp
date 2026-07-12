class Solution {
public:
    //Recursion
    // int f(int i, int j, string word1, string word2){
    //     if(i < 0) return j + 1;
    //     if(j < 0) return i + 1;

    //     if(word1[i] == word2[j]) return f(i - 1, j - 1, word1, word2);
    //     return min(1 + f(i - 1, j, word1, word2), min(1 + f(i, j - 1, word1, word2), 1 + f(i - 1, j - 1, word1, word2)));
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     return f(n - 1, m - 1, word1, word2);
    // }
    //Memoization
    // int f(int i, int j, string word1, string word2, vector<vector<int>> &dp){
    //     if(i < 0) return j + 1;
    //     if(j < 0) return i + 1;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(word1[i] == word2[j]) return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
    //     return dp[i][j] = min(1 + f(i - 1, j, word1, word2, dp), min(1 + f(i, j - 1, word1, word2, dp), 1 + f(i - 1, j - 1, word1, word2, dp)));
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return f(n - 1, m - 1, word1, word2, dp);
    // }
    //Tabulation
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();        
    //     int m = word2.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    //     for(int i = 0; i <= n; i++) dp[i][0] = i;
    //     for(int j = 0; j <= m; j++) dp[0][j] = j;

    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= m; j++){
    //             if(word1[i - 1] == word2[j - 1]){ 
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             }
    //             else {
    //                 dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }
    //Space Optimization
    int minDistance(string word1, string word2) {
        int n = word1.size();        
        int m = word2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){ 
                    cur[j] = prev[j - 1];
                }
                else {
                    cur[j] = min(1 + prev[j], min(1 + cur[j - 1], 1 + prev[j - 1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};