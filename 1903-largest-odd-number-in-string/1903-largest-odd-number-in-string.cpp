class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;

        int i;
        for (i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }
        i = 0;
        return num.substr(0, ind - i + 1);
    }
};