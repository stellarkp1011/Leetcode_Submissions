class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int e = 0;
        int o = 1;
        vector<int> ans(n);
        for(int i =0 ;i < n; i++) {
            if(nums[i] > 0) {
                ans[e] = nums[i];
                e += 2;
            } else {
                ans[o] = nums[i];
                o += 2;
            }
        }
        return ans;
    }
};