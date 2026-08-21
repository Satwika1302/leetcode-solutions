class Solution {
public:
    const int mod = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int solve(int i, int a, int l, int n) {

        if(i == n) {
            return 1;
        }

        if(dp[i][a][l] != -1) {
            return dp[i][a][l];
        }

        int k = 0;

        // Choose A
        if(a < 1) {
            k = (k + solve(i + 1, a + 1, 0, n)) % mod;
        }

        // Choose L
        if(l < 2) {
            k = (k + solve(i + 1, a, l + 1, n)) % mod;
        }

        // Choose P
        k = (k + solve(i + 1, a, 0, n)) % mod;

        return dp[i][a][l] = k;
    }

    int checkRecord(int n) {

        dp.assign(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(0, 0, 0, n);
    }
};