class Solution {
public:
    int maxel(int n, vector<int> &weights){
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, weights[i]);
        }
        return ans;
    }
    int arrsum(int n, vector<int> &weights){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
        }
        return sum;
    }
    int totaldays(int n, int mid, vector<int>& weights, int days) {
        int load = 0, day = 1;
        for(int i = 0; i < n; i++){
            if(load + weights[i] > mid){
                day = day + 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = maxel(n, weights);
        int high = arrsum(n, weights);

        while(low <= high){
            int mid = (low + high) / 2;

            if(totaldays(n, mid, weights, days) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};