class Solution {
public:
    string frequencySort(string s) {
        vector<pair <int, int>> freq(256);
        for(int i = 0; i < 256; i++) {
            freq[i] = {0, i};
        }

        for(char ch : s) {
            freq[ch].first++;
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        string ans = "";
        for(auto p : freq) {
            int cnt = p.first;
            char ch = p.second;

            ans += string(cnt, ch);
        }

        return ans;
    }
};