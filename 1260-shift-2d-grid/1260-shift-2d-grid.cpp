class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        k = k % total;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int ind = i * n + j;

                int newInd = (ind + k) % total;

                int newRow = newInd / n;
                int newCol = newInd % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};