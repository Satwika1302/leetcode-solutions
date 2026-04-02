#define ll long long
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        ll m = coins.size();
        ll n = coins[0].size();

        // Initialize DP array with INT_MIN
        vvvi dp(m, vvi(n, vi(3, INT_MIN)));

        // Base case: starting cell
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        // Fill the first row
        for (int j = 1; j < n; j++) {
            for (int k = 0; k <= 2; k++) {
                if (dp[0][j - 1][k] == INT_MIN) continue;
                if (coins[0][j] >= 0) {
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j - 1][k] + coins[0][j]);
                } else {
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j - 1][k] + coins[0][j]);
                }
                if (k < 2 && coins[0][j] < 0) {
                    dp[0][j][k + 1] = max(dp[0][j][k + 1], dp[0][j - 1][k]);
                }
            }
        }

        // Fill the first column
        for (int i = 1; i < m; i++) {
            for (int k = 0; k <= 2; k++) {
                if (dp[i - 1][0][k] == INT_MIN) continue;
                if (coins[i][0] >= 0) {
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][0][k] + coins[i][0]);
                } else {
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][0][k] + coins[i][0]);
                }
                if (k < 2 && coins[i][0] < 0) {
                    dp[i][0][k + 1] = max(dp[i][0][k + 1], dp[i - 1][0][k]);
                }
            }
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (dp[i][j - 1][k] != INT_MIN) {
                        if (coins[i][j] >= 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                        } else {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                        }
                        if (k < 2 && coins[i][j] < 0) {
                            dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j - 1][k]);
                        }
                    }
                    if (dp[i - 1][j][k] != INT_MIN) {
                        if (coins[i][j] >= 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                        } else {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                        }
                        if (k < 2 && coins[i][j] < 0) {
                            dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i - 1][j][k]);
                        }
                    }
                }
            }
        }

        // Find the maximum result among the last cell's DP values
        int result = INT_MIN;
        for (int k = 0; k <= 2; k++) {
            result = max(result, dp[m - 1][n - 1][k]);
        }

        return result;
    }
};