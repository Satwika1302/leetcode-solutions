class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n + 1, 0);

        for(int i = 2; i <= n; i++) {

            for(int j = 1; j < i; j++) {

                int noBreak =
                    j * (i - j);

                int breakAgain =
                    j * dp[i - j];

                dp[i] = max(
                    dp[i],
                    max(noBreak, breakAgain)
                );
            }
        }

        return dp[n];
    }
};