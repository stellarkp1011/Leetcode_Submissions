class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";

        vector<string> unit = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> multiplier = {"", "Thousand", "Million", "Billion"};

        string result = "";
        int group = 0;
        while(num > 0) {
            if(num % 1000 != 0){
                int value = (num % 1000);
                string temp = "";

                if(value >= 100) {
                    temp += unit[value / 100] + " Hundred ";
                    value = value % 100;
                }

                if(value > 19) {
                    temp += tens[value / 10] + " ";
                    value = value % 10;
                }

                if(value > 0) {
                    temp += unit[value] + " ";
                }

                temp += multiplier[group] + " ";
                result = temp + result;
            }
            group++;
            num /= 1000;
        }
        while(!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};