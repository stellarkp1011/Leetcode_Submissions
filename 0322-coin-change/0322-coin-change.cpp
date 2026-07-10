class Solution {
public:
    // int change(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(amount % coins[0] == 0) return amount / coins[0];
    //         else return -1;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int notTake = change(ind - 1, coins, amount, dp);
    //     int take = 1e9;
    //     if(coins[ind] <= amount) take = 1 + change(ind, coins, amount - coins[ind], dp);

    //     return dp[ind][amount] = min(take, notTake);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    //     return change(n - 1, coins, amount, dp);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    //     for(int t = 0; t <= amount; t++){
    //         if(t % coins[0] == 0) dp[0][t] = t / coins[0];
    //         else dp[0][t] = 1e9;
    //     }
    //     for(int ind = 1; ind < n; ind++){
    //         for(int tar = 0; tar <= amount; tar++){
    //             int notTake = dp[ind - 1][tar];
    //             int take = 1e9;
    //             if(coins[ind] <= tar) take = 1 + dp[ind][tar - coins[ind]];

    //             dp[ind][tar] = min(take, notTake);
    //         }
    //     }
    //     int ans = dp[n - 1][amount];
    //     if(ans == 1e9) return -1;
    //     return ans;
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = 1e9;
        }
        for(int ind = 1; ind < n; ind++){
            for(int tar = 0; tar <= amount; tar++){
                int notTake = prev[tar];
                int take = 1e9;
                if(coins[ind] <= tar) take = 1 + cur[tar - coins[ind]];

                cur[tar] = min(take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans == 1e9) return -1;
        return ans;
    }
};