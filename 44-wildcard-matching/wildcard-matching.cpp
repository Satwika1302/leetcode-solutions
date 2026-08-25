class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base Case
        dp[0][0] = true;

        // Pattern vs Empty String
        for (int j = 1; j <= m; j++) {
            dp[0][j] = isAllStars(p, j);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Current characters match or '?'
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Current pattern character is '*'
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }

private:
    bool isAllStars(string &p, int len) {
        for (int i = 0; i < len; i++) {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
};