//Recursion
// class Solution {
// public:
//     int solve(int i, int j, int k, int m, int n,
//               vector<vector<int>>& grid) {

//         int mx = k;

//         // upper-right
//         if(i - 1 >= 0 && j + 1 < n &&
//            grid[i - 1][j + 1] > grid[i][j]) {
//             mx = max(mx,
//                      solve(i - 1, j + 1, k + 1, m, n, grid));
//         }

//         // right
//         if(j + 1 < n &&
//            grid[i][j + 1] > grid[i][j]) {
//             mx = max(mx,
//                      solve(i, j + 1, k + 1, m, n, grid));
//         }

//         // lower-right
//         if(i + 1 < m && j + 1 < n &&
//            grid[i + 1][j + 1] > grid[i][j]) {
//             mx = max(mx,
//                      solve(i + 1, j + 1, k + 1, m, n, grid));
//         }

//         return mx;
//     }

//     int maxMoves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         int mx = 0;

//         for(int i = 0; i < m; i++) {
//             mx = max(mx, solve(i, 0, 0, m, n, grid));
//         }

//         return mx;
//     }
// };


//Memoization
// class Solution {
// public:
//     int solve(int i, int j,
//               vector<vector<int>>& grid,
//               vector<vector<int>>& dp) {

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         int m = grid.size();
//         int n = grid[0].size();

//         int mx = 0;

//         if(i - 1 >= 0 && j + 1 < n &&
//            grid[i - 1][j + 1] > grid[i][j]) {
//             mx = max(mx, 1 + solve(i - 1, j + 1, grid, dp));
//         }

//         if(j + 1 < n &&
//            grid[i][j + 1] > grid[i][j]) {
//             mx = max(mx, 1 + solve(i, j + 1, grid, dp));
//         }

//         if(i + 1 < m && j + 1 < n &&
//            grid[i + 1][j + 1] > grid[i][j]) {
//             mx = max(mx, 1 + solve(i + 1, j + 1, grid, dp));
//         }

//         return dp[i][j] = mx;
//     }

//     int maxMoves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         int ans = 0;

//         for(int i = 0; i < m; i++) {
//             ans = max(ans, solve(i, 0, grid, dp));
//         }

//         return ans;
//     }
// };

//DP
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int j = n - 2; j >= 0; j--) {

            for(int i = 0; i < m; i++) {

                int mx = 0;

                // upper-right
                if(i - 1 >= 0 &&
                   grid[i - 1][j + 1] > grid[i][j]) {

                    mx = max(mx, 1 + dp[i - 1][j + 1]);
                }

                // right
                if(grid[i][j + 1] > grid[i][j]) {

                    mx = max(mx, 1 + dp[i][j + 1]);
                }

                // lower-right
                if(i + 1 < m &&
                   grid[i + 1][j + 1] > grid[i][j]) {

                    mx = max(mx, 1 + dp[i + 1][j + 1]);
                }

                dp[i][j] = mx;
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};