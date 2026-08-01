class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n = nums.size();
    //     int cnt = 0;
    //     for(int i = 0; i < n; i++) {
    //         int sum = 0;
    //         for(int j = i; j < n; j++) {
    //             sum += nums[j];
    //             if(sum == goal) {
    //                 cnt++;
    //             }
    //             if(sum > goal) break;
    //         }
    //     }
    //     return cnt;
    // }
    int fun(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;
        while(r < n) {
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            if(sum <= goal) {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums, goal) - fun(nums, goal - 1);
    }
};