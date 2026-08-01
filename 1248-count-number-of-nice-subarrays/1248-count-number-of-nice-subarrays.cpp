class Solution {
public:
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int nice = 0;
    //     for(int i = 0; i < n; i++) {
    //         int cnt  = 0;
    //         for(int j = i; j < n; j++) {
    //             if(nums[j ] % 2 == 1) cnt++;
    //             if(cnt == k) {
    //                 nice++;
    //             }
    //             if(cnt > k) break;
    //         }
    //     }
    //     return nice;
    // }
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < n){
            sum += (nums[r] % 2);
            while(sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            if(sum <= k) {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};