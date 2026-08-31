class Solution {
public:
    int solve(int i, int rDays, vector<int>& jobDifficulty, int n,
              vector<vector<int>>& dp) {

        if (rDays == 0)
            return i == n ? 0 : INT_MAX;

        if (i == n)
            return INT_MAX;

        int mn = INT_MAX;
        int mx = 0;

        if (dp[i][rDays] != -1)
            return dp[i][rDays];

        for (int j = i; j < n; j++) {

            mx = max(mx, jobDifficulty[j]);

            int next = solve(j + 1, rDays - 1, jobDifficulty, n, dp);

            if (next != INT_MAX) {
                mn = min(mn, mx + next);
            }
        }

        return dp[i][rDays] = mn;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();

        if (n < d)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return solve(0, d, jobDifficulty, n, dp);
    }
};