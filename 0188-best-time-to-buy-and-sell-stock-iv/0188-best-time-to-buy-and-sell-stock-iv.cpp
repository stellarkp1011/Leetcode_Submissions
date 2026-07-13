class Solution {
public:
    // recursion
    // int func(int ind, int transaction, int n, int k, vector<int>& prices){
    //     if(ind == n) return 0;
    //     if(transaction == 2 * k) return 0;

    //     int profit = 0;
    //     if(transaction % 2 == 0){       //buy
    //         profit = max(-prices[ind] + func(ind + 1, transaction + 1, n, k, prices), func(ind + 1, transaction, n, k, prices));
    //     } else { // sell
    //         profit = max(prices[ind] + func(ind + 1, transaction + 1, n, k, prices), func(ind + 1, transaction, n, k, prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     return func(0, 0, n, k, prices);
    // }

    //Memoization
    //     int func(int ind, int transaction, int n, int k, vector<int>& prices, vector<vector<int>>& dp){
    //     if(ind == n) return 0;
    //     if(transaction == 2 * k) return 0;

    //     if(dp[ind][transaction] != -1) return dp[ind][transaction];
    //     int profit = 0;
    //     if(transaction % 2 == 0){       //buy
    //         profit = max(-prices[ind] + func(ind + 1, transaction + 1, n, k, prices, dp), func(ind + 1, transaction, n, k, prices, dp));
    //     } else { // sell
    //         profit = max(prices[ind] + func(ind + 1, transaction + 1, n, k, prices, dp), func(ind + 1, transaction, n, k, prices, dp));
    //     }
    //     return dp[ind][transaction] = profit;
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));
    //     return func(0, 0, n, k, prices, dp);
    // }

    //Tabulation
    //     int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int transaction = 0; transaction < 2*k; transaction++){
    //             int profit = 0;
    //             if(transaction % 2 == 0){   //buy
    //                 profit = max(-prices[ind] + dp[ind + 1][transaction + 1], dp[ind + 1][transaction]);
    //             } else {    //sell
    //                 profit = max(prices[ind] + dp[ind + 1][transaction + 1], dp[ind + 1][transaction]);
    //             }
    //             dp[ind][transaction] = profit;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //Space optimization
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        vector<int> prev(2 * k + 1, 0), cur(2 * k + 1, 0);
        for(int ind = n - 1; ind >= 0; ind--){
            for(int transaction = 0; transaction < 2*k; transaction++){
                int profit = 0;
                if(transaction % 2 == 0){   //buy
                    profit = max(-prices[ind] + prev[transaction + 1], prev[transaction]);
                } else {    //sell
                    profit = max(prices[ind] + prev[transaction + 1], prev[transaction]);
                }
                cur[transaction] = profit;
            }
            prev = cur;
        }
        return prev[0];
    }
};