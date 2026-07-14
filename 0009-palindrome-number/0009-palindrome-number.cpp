class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        long newx = 0;
        int n = x;
        while(x > 0){
            newx = newx * 10 + (x % 10);
            x = x / 10;
        }
        if(newx == n){
            return true;
        } else {
            return false;
        }
    }
};