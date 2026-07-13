class Solution {
public:
    // Recursion
    // int func(int ind, int buy, int fee, int n, vector<int>& prices){
    //     if(ind == n) return 0;

    //     int profit = 0;
    //     if(buy == 1){
    //         profit = max(-prices[ind] + func(ind + 1, 0, fee, n, prices), func(ind + 1, 1, fee, n, prices));
    //     } else {
    //         profit = max(prices[ind] + func(ind + 1, 1, fee, n, prices) - fee, func(ind + 1, 0, fee, n, prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     return func(0, 1, fee, n, prices);
    // }

    //Memoization
    //     int func(int ind, int buy, int fee, int n, vector<int>& prices, vector<vector<int>> &dp){
    //     if(ind == n) return 0;

    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit = 0;
    //     if(buy == 1){
    //         profit = max(-prices[ind] + func(ind + 1, 0, fee, n, prices, dp), func(ind + 1, 1, fee, n, prices, dp));
    //     } else {
    //         profit = max(prices[ind] + func(ind + 1, 1, fee, n, prices, dp) - fee, func(ind + 1, 0, fee, n, prices, dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return func(0, 1, fee, n, prices, dp);
    // }

    //Tabulation
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int buy = 0; buy < 2; buy++){
    //             int profit = 0;
    //             if(buy == 1){
    //                 profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
    //             } else {
    //                 profit = max(prices[ind] + dp[ind + 1][1] - fee, dp[ind + 1][0]);
    //             }
    //             dp[ind][buy] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }

    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
    //         dp[ind][0] = max(prices[ind] + dp[ind + 1][1] - fee, dp[ind + 1][0]);
    //     }
        
    //     return dp[0][1];
    // }

    //Space optimization
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2, 0), cur(2, 0);
        
        for(int ind = n - 1; ind >= 0; ind--){
            cur[1] = max(-prices[ind] + prev[0], prev[1]);
            cur[0] = max(prices[ind] + prev[1] - fee, prev[0]);

            prev = cur;
        }
        return prev[1];
    }
};