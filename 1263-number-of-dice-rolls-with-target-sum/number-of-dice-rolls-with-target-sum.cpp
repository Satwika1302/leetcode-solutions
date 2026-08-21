class Solution {
public:
    const int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target+1,0));
        
            for (int j = 1; j <= target ; j++) {
                if(j<=k){
                dp[1][j]=1;
                }else{
                    dp[1][j]=0;
                }
            }


        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int p = 1; p <= k; p++) {
                    if(p<=j){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};