class Solution {
public:
    int maxel(int n, vector<int> &nums){
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    int arrsum(int n, vector<int> &nums){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        return sum;
    }
    int largest(int n, int mid, vector<int> &nums) {
        int totalk = 1, load = 0;
        for(int i = 0; i < n; i++) {
            if(load + nums[i] <= mid) {
                load += nums[i];
            } else {
                totalk++;
                load = nums[i];
            }
        }
        return totalk;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = maxel(n, nums);
        int high = arrsum(n, nums);

        while(low <= high) {
            int mid = (low + high) / 2;

            if(largest(n, mid, nums) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};