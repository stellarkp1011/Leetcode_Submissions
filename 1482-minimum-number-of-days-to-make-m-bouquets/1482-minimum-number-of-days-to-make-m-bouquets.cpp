class Solution {
public:
    bool possible(int mid, vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, totalCnt = 0; 
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                cnt++;
            } else {
                totalCnt += (cnt / k);
                cnt = 0;
            }
        }
        totalCnt += (cnt / k);

        if(totalCnt >= m) return true;
        return false;
    }
    int minel(vector<int>& bloomDay){
        int n = bloomDay.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, bloomDay[i]);
        }
        return ans;
    }
    int maxel(vector<int>& bloomDay){
        int n = bloomDay.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, bloomDay[i]);
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        int n = bloomDay.size();
        if(val > n) return -1;
        int low = minel(bloomDay);
        int high = maxel(bloomDay);
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;

            if(possible(mid, bloomDay, m, k) == true){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};