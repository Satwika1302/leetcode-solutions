class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int people, int p, int n, int minProfit,
              vector<int>& group, vector<int>& profit,
              vector<vector<vector<int>>>& dp) {

        if (i == group.size()) {
            return p == minProfit;
        }

        if (dp[i][people][p] != -1) {
            return dp[i][people][p];
        }

        long long ans = 0;

        // Skip current crime
        ans += solve(i + 1, people, p, n, minProfit, group, profit, dp);

        // Take current crime
        if (people + group[i] <= n) {

            int newPeople = people + group[i];

            int newProfit = min(minProfit, p + profit[i]);

            ans += solve(i + 1, newPeople, newProfit, n, minProfit, group,
                         profit, dp);
        }

        return dp[i][people][p] = ans % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {

        int crimes = group.size();

        vector<vector<vector<int>>> dp(
            crimes, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

        return solve(0, 0, 0, n, minProfit, group, profit, dp);
    }
};