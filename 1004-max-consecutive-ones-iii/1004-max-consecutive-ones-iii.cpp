class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int l = 0, r = 0, maxlen = 0, zero = 0;
    //     while(r < n) {
    //         if(nums[r] == 0) {
    //             zero++;
    //         }
    //         while(zero > k) {
    //             if(nums[l] == 0) zero--;
    //             l++;
    //         }
    //         if(zero <= k){
    //             int len = r - l + 1;
    //             maxlen = max(maxlen, len); 
    //         }
    //         r++;
    //     }
    //     return maxlen;
    // }
        int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxlen = 0, zero = 0;
        while(r < n) {
            if(nums[r] == 0) {
                zero++;
            }
            if(zero > k) {
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                int len = r - l + 1;
                maxlen = max(maxlen, len); 
            }
            r++;
        }
        return maxlen;
    }
};