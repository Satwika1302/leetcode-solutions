// For every row below, keep:
// the smallest value
// the column of the smallest value
// the second smallest value
// Then for current cell (i, j):
// if j != minCol, use the smallest
// if j == minCol, use the second smallest

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i = n - 2; i >= 0; i--) {

            int mn1 = INT_MAX;
            int mn2 = INT_MAX;
            int minCol = -1;

            // Find smallest and second smallest in next row
            for(int j = 0; j < n; j++) {

                int val = grid[i + 1][j];

                if(val < mn1) {
                    mn2 = mn1;
                    mn1 = val;
                    minCol = j;
                }
                else if(val < mn2) {
                    mn2 = val;
                }
            }

            // Build current row
            for(int j = 0; j < n; j++) {

                if(j == minCol) {
                    grid[i][j] += mn2;
                }
                else {
                    grid[i][j] += mn1;
                }
            }
        }

        int ans = grid[0][0];

        for(int j = 1; j < n; j++) {
            ans = min(ans, grid[0][j]);
        }

        return ans;
    }
};