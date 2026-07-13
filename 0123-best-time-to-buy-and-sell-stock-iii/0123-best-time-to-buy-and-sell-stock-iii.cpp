class Solution {
public:
    // Recursion
    // int func(int ind, int buy, vector<int> &prices, int n, int cap){
    //     if(cap == 0) return 0;
    //     if(ind == n) return 0;
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + func(ind + 1, 0, prices, n, cap), func(ind + 1, 1, prices, n, cap));
    //     } else {
    //         profit = max((prices[ind] + func(ind + 1, 1, prices, n, cap - 1)), func(ind + 1, 0, prices, n, cap));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return func(0, 1, prices, n, 2);
    // }
    // Memoization
    // int func(int ind, int buy, vector<int> &prices, int n, int cap, vector<vector<vector<int>>>& dp){
    //     if(cap == 0) return 0;
    //     if(ind == n) return 0;
    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + func(ind + 1, 0, prices, n, cap, dp), func(ind + 1, 1, prices, n, cap, dp));
    //     } else {
    //         profit = max((prices[ind] + func(ind + 1, 1, prices, n, cap - 1, dp)), func(ind + 1, 0, prices, n, cap, dp));
    //     }
    //     return dp[ind][buy][cap] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    //     return func(0, 1, prices, n, 2, dp);
    // }
    //Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0));
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int buy = 0; buy < 2; buy++){
    //             for(int cap = 1; cap < 3; cap++){
    //                 int profit = 0;
    //                 if(buy){
    //                     profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
    //                 } else {
    //                     profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
    //                 }
    //                 dp[ind][buy][cap] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }
    // Space optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap < 3; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind] + prev[0][cap], prev[1][cap]);
                    } else {
                        profit = max(prices[ind] + prev[1][cap - 1], prev[0][cap]);
                    }
                    cur[buy][cap] = profit;
                }
            }
            prev = cur;
        }
        return prev[1][2];
    }
};