class Solution {
public:
    // Recursion
    // bool f(int i, int j, string &s, string &p){
    //     if(i < 0 && j < 0) return true;
    //     if(j < 0 && i >= 0) return false;
    //     if(j >= 0 && i < 0) {
    //         for(int it = 0; it <= j; it++){
    //             if(p[it] != '*') return false;
    //         }
    //         return true;
    //     }

    //     if(s[i] == p[j] || p[j] == '?'){
    //         return f(i - 1, j - 1, s, p);
    //     } else if(p[j] == '*') {
    //         return f(i, j - 1, s, p) || f(i - 1, j, s, p);
    //     } else {
    //         return false;
    //     }
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     return f(n - 1, m - 1, s, p);
    // }
    //Memoization
    // bool f(int i, int j, string &s, string &p, vector<vector<int>>& dp){
    //     if(i < 0 && j < 0) return true;
    //     if(j < 0 && i >= 0) return false;
    //     if(j >= 0 && i < 0) {
    //         for(int it = 0; it <= j; it++){
    //             if(p[it] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == p[j] || p[j] == '?'){
    //         return dp[i][j] = f(i - 1, j - 1, s, p, dp);
    //     } else if(p[j] == '*') {
    //         return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
    //     } else {
    //         return dp[i][j] = false;
    //     }
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return f(n - 1, m - 1, s, p, dp);
    // }
    // Tabulation
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    //     dp[0][0] = true;
    //     for(int i = 1; i <= n; i++) dp[i][0] = false;
    //     for(int j = 1; j <= m; j++){
    //         bool flag = true;
    //         for(int k = 0; k < j; k++){
    //             if(p[k] != '*'){ 
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         dp[0][j] = flag;
    //     }
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= m; j++){
    //             if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             } else if(p[j - 1] == '*') {
    //                 dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
    //             } else {
    //                 dp[i][j] = false;
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }
    //Space Optimization
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false), cur(m + 1, false);
        prev[0] = true;
        // for(int i = 1; i <= n; i++) dp[i][0] = false;
        for(int j = 1; j <= m; j++){
            bool flag = true;
            for(int k = 0; k < j; k++){
                if(p[k] != '*'){ 
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for(int i = 1; i <= n; i++){
            cur[0] = false;
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    cur[j] = prev[j - 1];
                } else if(p[j - 1] == '*') {
                    cur[j] = cur[j - 1] || prev[j];
                } else {
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};