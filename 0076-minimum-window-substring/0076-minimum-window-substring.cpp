class Solution {
public:
    // string minWindow(string s, string t) {
    //     int n = s.length();
    //     int m = t.size();
    //     // int cnt = 0;
    //     int minLen = 1e9, startI = -1;;
    //     for(int i = 0; i < n; i++) {
    //         vector<int> hash(256, 0);
    //         for(int j = 0; j < m; j++)  hash[t[j]]++;
    //         int cnt = 0;
    //         for(int j = i; j < n; j++) {
    //             if(hash[s[j]] > 0) cnt++;
    //             hash[s[j]]--;
    //             if(cnt == m) {
    //                 if((j - i + 1) < minLen) {
    //                     minLen = (j - i + 1);
    //                     startI = i;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     if(startI == -1) return "";
    //     return s.substr(startI, minLen);
    // }

    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.size();
        vector<int> hash(256, 0);
        int l = 0, r = 0, minLen = 1e9, cnt = 0, startI = -1;
        for(int i = 0; i < m; i++) hash[t[i]]++;

        while(r < n) {
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m) {
                if((r - l + 1) < minLen) {
                    minLen = (r - l + 1);
                    startI = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(startI == -1) return "";
        return s.substr(startI, minLen);
    }
};