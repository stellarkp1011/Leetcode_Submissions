class Solution {
public:
    // string reverseWords(string s) {
    //     string res = "";
    //     string word = "";
    //     for (char ch : s){
    //         if(ch != ' '){
    //             word += ch;
    //         } else {
    //             if(!word.empty()){
    //                 if(!res.empty()) res = word + " " + res;
    //                 else res = word + res;
    //                 word = "";
    //             }
    //         }
    //     }
    //     if(!word.empty()){
    //         if(!res.empty()) res = word + " " + res;
    //         else res = word + res;
    //    }
    //     return res;
    // }

    string reverseWords(string s) {
        string res = "";
        int i = s.size() - 1;

        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') i--;

            if(i < 0) break;

            int end = i;

            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            string word = s.substr(i + 1, end - i);

            if(!res.empty()) {
                res += ' ';
            }

            res += word;
        }
        return res;
    }
};