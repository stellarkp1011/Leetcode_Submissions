class Solution {
public:
    int reverse(int x) {
        long long n = abs((long long)x);
        long long revNo = 0;
        while(n > 0) {
            int lastdigit = n % 10;
            n = n / 10;
            revNo = (revNo * 10) + lastdigit;
        }
        if(x < 0) revNo = 0 - revNo;
        if(revNo > INT_MAX || revNo < INT_MIN) return 0;
        return (int)revNo;
    }
};