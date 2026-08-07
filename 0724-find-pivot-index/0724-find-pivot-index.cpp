class Solution {
public:
    int sum(int i, int j, vector<int>& nums, int n) {
        int sums = 0;
        for(int k = i; k <= j; k++) {
            sums += nums[k];
        }
        return sums;
    }
    int pivotIndex(vector<int>& nums) {
        int pivot = 0;
        int n = nums.size();
        while(pivot < n) {
            int sum1 = sum(0, pivot - 1, nums, n);
            int sum2 = sum(pivot + 1, n - 1, nums, n);

            if(sum1 == sum2) return pivot;

            pivot++;
        }
        return -1;
    }
};