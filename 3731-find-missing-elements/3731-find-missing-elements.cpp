class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            st.insert(nums[i]);
        }
        for(int i = mini; i <= maxi; i++) {
            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};