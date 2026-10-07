class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        int n = num;
        for(int i = 1; i <= num / 2; i++) {
            if(num % i == 0){
                cout << i << endl;
                sum += i;
            }
        }
        if(sum == num) return true;
        return false;
    }
};