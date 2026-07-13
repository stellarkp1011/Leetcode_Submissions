class Solution {
public:
    // Recursion
    // int func(int ind, int buy, int n, vector<int> & prices){
    //     if(ind >= n) return 0;

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + func(ind + 1, 0, n, prices), func(ind + 1, 1, n, prices));
    //     } else {
    //         profit = max(prices[ind] + func(ind + 2, 1, n, prices), func(ind + 1, 0, n, prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return func(0, 1, n, prices);
    // }

    // Memoization
    //     int func(int ind, int buy, int n, vector<int> & prices, vector<vector<int>>& dp){
    //     if(ind >= n) return 0;


    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + func(ind + 1, 0, n, prices, dp), func(ind + 1, 1, n, prices, dp));
    //     } else {
    //         profit = max(prices[ind] + func(ind + 2, 1, n, prices, dp), func(ind + 1, 0, n, prices, dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return func(0, 1, n, prices, dp);
    // }

    // Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int buy = 0; buy < 2; buy++){
    //             int profit = 0;
    //             if(buy){
    //                 profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
    //             } else {
    //                 profit = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
    //             }
    //             dp[ind][buy] = profit;      
    //         }
    //     }
    //     return dp[0][1];
    // }

    //Space optimization
        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        vector<int> cur(2, 0);

        for(int ind = n - 1; ind >= 0; ind--){
            cur[1] = max(-prices[ind] + front1[0], front1[1]);

            cur[0] = max(prices[ind] + front2[1], front1[0]);

            front2 = front1;
            front1 = cur;
        }
        return cur[1];
    }
};