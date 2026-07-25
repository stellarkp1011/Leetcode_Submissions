class Solution {
public:
    int maxProduct(int n) {
        int largest = -1, secLargest = -1;
        while(n > 0) {
            int digit = n % 10;

            if(digit > largest) {
                secLargest = largest;
                largest = digit;
            } else if(digit >= secLargest) {
                secLargest = digit;
            }

            n = n / 10;
        } 
        if(secLargest != -1) return largest * secLargest;
        return largest * largest;
    }
};