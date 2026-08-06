class Solution {
public:
    int pro(int n) {
        int mul = 1;
        while(n > 0) {
            int d = n % 10;
            mul = mul * d;
            n /= 10;
        }
        return mul;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(i >= 0) {
            if(pro(i) % t == 0) return i;
            i++;
        }
        return -1;
    }
};