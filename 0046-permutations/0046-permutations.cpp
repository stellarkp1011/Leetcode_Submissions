class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0) {
            return {{}};
        }
        for(int i = 0; i < n; i++) {
            int ith = nums[i];
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                if(i != j){
                    temp.push_back(nums[j]);
                }
            }
            vector<vector<int>> perms = permute(temp);
            for(vector<int> p : perms) {
                p.insert(p.begin(), ith);
                res.push_back(p);
            }
        }
        return res;
    }
};