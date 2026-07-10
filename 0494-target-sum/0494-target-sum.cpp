class Solution {
public:
    int findWays(vector<int> &nums, int target){
        int n = nums.size();
        vector<int> prev(target + 1, 0), cur(target + 1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;
        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= target; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(nums[ind] <= sum) take = prev[sum - nums[ind]];
                cur[sum] = take + notTake;
            }
            prev = cur;
        } 
        return prev[target];
    }
    int countPartitions(vector<int> &nums, int target){
        int totalSum = 0;
        for(auto it : nums) totalSum += it;
        if((totalSum - target < 0 ) || (totalSum - target) % 2) return false;
        return findWays(nums, (totalSum - target) / 2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};