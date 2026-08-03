class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        vector<int> copy1 = nums1;
        vector<pair<int, int>> original;
        for(int i = 0; i < n; i++) {
            original.push_back({nums2[i], i});
        }
        sort(original.begin(), original.end());
        sort(copy1.begin(), copy1.end());
        int left = 0, right = n - 1;
        for(int it : copy1) {
            if(it > original[left].first) {
                ans[original[left].second] = it;
                left++;
            } else {
                ans[original[right].second] = it;
                right--;
            }
        }
        return ans;
    }
};