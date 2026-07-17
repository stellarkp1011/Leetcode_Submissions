class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxA = INT_MIN;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int ht = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * ht);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        int maxR = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxR = max(maxR, area);
        }
        return maxR;
    }
};