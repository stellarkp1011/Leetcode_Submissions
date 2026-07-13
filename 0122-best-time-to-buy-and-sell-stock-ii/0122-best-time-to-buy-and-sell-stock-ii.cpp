class Solution {
public:
    // Recursion
    // int prof(int ind, int buy, vector<int>& prices,int n){
    //     if(ind == n) return 0;
    //     int profit = 0; 
    //     if(buy) {
    //         profit = max(-prices[ind] + prof(ind + 1, 0, prices, n), prof(ind + 1, 1, prices, n));
    //     } else {
    //         profit = max(prices[ind] + prof(ind + 1, 1, prices, n), prof(ind + 1, 0, prices, n));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return prof(0, 1, prices, n);
    // }

    //memoization
    // int prof(int ind, int buy, vector<int>& prices,int n, vector<vector<int>>& dp){
    //     if(ind == n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit = 0; 
    //     if(buy) {
    //         profit = max(-prices[ind] + prof(ind + 1, 0, prices, n, dp), prof(ind + 1, 1, prices, n, dp));
    //     } else {
    //         profit = max(prices[ind] + prof(ind + 1, 1, prices, n, dp), prof(ind + 1, 0, prices, n, dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return prof(0, 1, prices, n, dp);
    // }
    //Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    //     dp[n][0] = 0;
    //     dp[n][1] = 0;
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int buy = 0; buy < 2; buy++){
    //             if(buy) {
    //                 dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
    //             } else {
    //                 dp[ind][buy] = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }
    // Space Optimization
        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0), cur(2, 0);
        prev[0] = prev[1] = 0;
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                if(buy) {
                    cur[buy] = max(-prices[ind] + prev[0], prev[1]);
                } else {
                    cur[buy] = max(prices[ind] + prev[1], prev[0]);
                }
            }
            prev = cur;
        }
        return prev[1];
    }
};