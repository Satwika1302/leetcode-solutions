// dp[i][j] =minimum health required when entering this cell
// I want the cheaper requirement:
// min(right, down)
// Then ask:
// How does the current dungeon value change that requirement?
// If current cell is -5, I need 5 extra.
// If current cell is +5, I need 5 less.
// Thus:
// need - dungeon[i][j]
// And because health must stay at least 1:
// max(1, need - dungeon[i][j])
// That's how you arrive at the recurrence instead of memorizing it.

// Base case: princess cell
// At the bottom-right cell:
// dungeon[m-1][n-1]
// you need enough health to survive that cell.
// If princess cell is:
// -5
// You need:
// 6
// because:
// 6 - 5 = 1
// So:
// dp[m-1][n-1] =
//     max(1, 1 - dungeon[m-1][n-1]);
// If princess cell is:
// +10
// then:
// 1 - 10 = -9
// so:
// dp = max(1,-9) = 1
// You only need 1 health entering.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {

                int need = min(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] = max(1, need - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};