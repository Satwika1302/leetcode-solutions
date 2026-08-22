class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& matrix) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        long long sum = 1;

        for(int d = 0; d < 4; d++) {

            int ni = i + dr[d];
            int nj = j + dc[d];

            if(ni >= 0 && ni < m &&
               nj >= 0 && nj < n &&
               matrix[ni][nj] > matrix[i][j]) {

                sum = (sum + solve(ni, nj, matrix)) % MOD;
            }
        }

        return dp[i][j] = sum;
    }

    int countPaths(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        long long ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                ans = (ans + solve(i, j, matrix)) % MOD;
            }
        }

        return ans;
    }
};