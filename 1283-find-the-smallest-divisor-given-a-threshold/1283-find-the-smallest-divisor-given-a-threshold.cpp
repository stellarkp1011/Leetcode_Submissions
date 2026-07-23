class Solution {
public:
    int maxel(int n, vector<int>& nums){
        int result = INT_MIN;
        for(int i = 0; i < n; i++){
            result = max(result, nums[i]);
        }
        return result;
    }
    bool isPossible(int n, int mid, vector<int>& nums, int threshold){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i] /(double)mid);
        }
        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low  = 1;
        int high = maxel(n, nums);
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(n, mid, nums, threshold) == true){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};