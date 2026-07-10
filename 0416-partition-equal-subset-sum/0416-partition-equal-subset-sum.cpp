class Solution {
public:
    // bool func(int ind, vector<int>& nums, int target, vector<vector<int>> &dp){
    //     if(target == 0) return true;
    //     if(ind == 0) return nums[0] == target;
    //     if(dp[ind][target] != -1) return dp[ind][target];
    //     bool notTake = func(ind - 1, nums, target, dp);
    //     bool take = false;
    //     if(nums[ind] <= target) take = func(ind - 1, nums, target - nums[ind], dp);
    //     return dp[ind][target] = take || notTake;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += nums[i];
    //     }
    //     int k = sum/2;
    //     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    //     if(sum % 2 != 0) return false;
    //     return func(n - 1, nums, sum/2, dp);
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += nums[i];
    //     }
    //     int k = sum/2;
    //     vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    //     if(sum % 2 != 0) return false;
    //     for(int i = 0; i < n; i++)    dp[i][0] = true;
    //     dp[0][nums[0]] = true;
    //     for(int i = 1; i < n; i++){
    //         for(int j = 1; j <= k; j++){
    //             bool notTake = dp[i - 1][j];
    //             bool take = false;
    //             if(nums[i] <= j) take = dp[i - 1][j - nums[i]];
    //             dp[i][j] = take || notTake;
    //         }
    //     }
    //     return dp[n - 1][k];
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int k = sum/2;
        vector<bool> prev(k + 1, 0), cur(k + 1, 0);
        if(sum % 2 != 0) return false;
        prev[0] = cur[0] = true;
        if(nums[0] <= k)    prev[nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                bool notTake = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j - nums[i]];
                cur[j] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
};