class Solution {
public:
    int maxDepth(string s) {
        int level = 0;
        int maxLevel = INT_MIN;
        for(char ch : s) {
            if(ch == '(') {
                level++;
                maxLevel = max(maxLevel, level);
            }
            else if (ch == ')'){
                level--;
            }
        }
        return maxLevel == INT_MIN ? 0 : maxLevel;
    }
};