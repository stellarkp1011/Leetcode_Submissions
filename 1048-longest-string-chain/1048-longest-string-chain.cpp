class Solution {
public:
    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            } else {
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()) return true;
        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n + 1, 1);
        int maxi = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < i; j++){
                if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};