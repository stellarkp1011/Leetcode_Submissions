class Solution {
public:
    // int firstStableIndex(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++) {
    //         int maxi = *max_element(nums.begin(), nums.begin() + i + 1);
    //         int mini = *min_element(nums.begin() + i, nums.end());

    //         if(maxi - mini <= k) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }
        int pref = nums[0];
        for(int i = 0; i < n; i++) {
            pref = max(pref, nums[i]);
            int score = pref - suffix[i];
            if(score <= k) {
                return i;
            }
        }
        return -1;
    }
};