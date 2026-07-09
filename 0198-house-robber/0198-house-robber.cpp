class Solution {
public:
    // int f(int ind, vector<int>& nums, vector<int> &dp){
    //     if(ind < 0) return 0;
    //     if(ind == 0) return nums[ind];
    //     if(dp[ind] != -1) return dp[ind];

    //     int pick = nums[ind] + f(ind - 2, nums, dp);
    //     int notPick = 0 + f(ind - 1, nums, dp);

    //     return dp[ind]= max(pick, notPick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return f(n - 1, nums, dp);
    // }
    
    // int rob(vector<int> &nums){
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);
    //     for(int i = 2; i < n; i++){
    //         int take = nums[i] + dp[i - 2];
    //         int notTake = dp[i - 1];
    //         dp[i] = max(take, notTake);
    //     }
    //     return dp[n - 1];
    // }
    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int take = nums[i] + prev2;
            int notTake = prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};