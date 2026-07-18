class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;

                    if (i > 0 && grid[i - 1][j] == 1)
                        cnt++;

                    if (i < n - 1 && grid[i + 1][j] == 1)
                        cnt++;

                    if (j > 0 && grid[i][j - 1] == 1)
                        cnt++;

                    if (j < m - 1 && grid[i][j + 1] == 1)
                        cnt++;

                    sum += 4 - cnt;
                }
            }
        }

        return sum;
    }
};