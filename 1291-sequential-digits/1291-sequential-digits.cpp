class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string str = "123456789";
        for(int len = 2; len < 10; len++){
            for(int start = 0; start <= str.size() - len; start++){
                int data = stoi(str.substr(start, len));
                if(data >= low && data <= high){
                    result.push_back(data);
                }
            }
        }
        return result;
    }
};