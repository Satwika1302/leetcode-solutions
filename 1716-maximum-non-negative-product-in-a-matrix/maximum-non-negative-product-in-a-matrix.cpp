class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<pair<long long, long long>>> dp(
            m, vector<pair<long long, long long>>(n)
        );

        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                long long cur = grid[i][j];

                long long mx = LLONG_MIN;
                long long mn = LLONG_MAX;

                // from top
                if (i > 0) {
                    auto [tmax, tmin] = dp[i-1][j];
                    mx = max(mx, max(tmax * cur, tmin * cur));
                    mn = min(mn, min(tmax * cur, tmin * cur));
                }

                // from left
                if (j > 0) {
                    auto [lmax, lmin] = dp[i][j-1];
                    mx = max(mx, max(lmax * cur, lmin * cur));
                    mn = min(mn, min(lmax * cur, lmin * cur));
                }

                dp[i][j] = {mx, mn};
            }
        }

        long long res = dp[m-1][n-1].first;
        int mod = 1e9 + 7;

        return res < 0 ? -1 : res % mod;
    }
};