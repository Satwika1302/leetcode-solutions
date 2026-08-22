class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& matrix) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int mx = 1;

        for(int d = 0; d < 4; d++) {

            int ni = i + dr[d];
            int nj = j + dc[d];

            if(ni >= 0 && ni < m &&
               nj >= 0 && nj < n &&
               matrix[ni][nj] > matrix[i][j]) {

                mx = max(mx,
                         1 + solve(ni, nj, matrix));
            }
        }

        return dp[i][j] = mx;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};