class Solution {
public:
    // Memoization
    int func(int ind, int target, vector<int> &coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(target % coins[ind] == 0) return 1;
            else return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = func(ind - 1, target, coins, dp);
        int take = 0;
        if(coins[ind] <= target) take = func(ind, target - coins[ind], coins, dp);
        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, amount, coins, dp);
    }
    //Tabulation
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    //     for(int t = 0; t <= amount; t++){
    //         if(t % coins[0] == 0) dp[0][t] = 1;
    //         else dp[0][t] = 0;
    //     }
    //     for(int ind = 1; ind < n; ind++){
    //         for(int tar = 0; tar <= amount; tar++){
    //             int notTake = dp[ind - 1][tar];
    //             int take = 0;
    //             if(coins[ind] <= tar) take = dp[ind][tar - coins[ind]];
    //             dp[ind][tar] = take + notTake;
    //         }
    //     }
    //     return dp[n - 1][amount];
    // }
    // Space Optimization

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();

    //     if (coins.empty()) {
    //         return amount == 0;
    //     }
    //     vector<long long> prev(amount + 1, 0);
    //     for(int t = 0; t <= amount; t++){
    //         if(t % coins[0] == 0) prev[t] = 1;
    //         else prev[t] = 0;
    //     }
    //     for(int ind = 1; ind < n; ind++){
    //         vector<long long> cur(amount + 1, 0);
    //         cur[0] = 1;
    //         for(int tar = 0; tar <= amount; tar++){
    //             long long notTake = prev[tar];
    //             long long take = 0;
    //             if(coins[ind] <= tar) take = cur[tar - coins[ind]];
    //             cur[tar] = (take + notTake) % MOD;
    //         }
    //         prev = cur;
    //     }
    //     return prev[amount];
    // }
};