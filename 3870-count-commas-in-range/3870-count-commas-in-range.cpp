class Solution {
public:
    int countCommas(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(i >= 1000) {
                sum += 1;
            }
        }
        return sum;
    }
};