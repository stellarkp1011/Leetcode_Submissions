class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int pref = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            int remove = pref - k;
            cnt += mpp[remove];
            mpp[pref]++;
        }
        return cnt;
    }
};