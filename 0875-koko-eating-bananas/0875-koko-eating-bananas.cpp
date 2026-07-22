class Solution {
public:
    int maxel(vector<int>& piles){
        int n = piles.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, piles[i]);
        }
        return ans;
    }
    double hours(vector<int> &piles, int mid){
        int n = piles.size();
        double totalHrs = 0;
        for(int i = 0; i < n; i++){
            totalHrs += ceil((double)piles[i] / (double)mid);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxel(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(hours(piles, mid) <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};