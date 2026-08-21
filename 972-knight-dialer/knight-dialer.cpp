class Solution {
public:
    const int mod =1e9+7;
    vector<vector<int>>path = {{4, 6},{6, 8},{7, 9},{4, 8},{0, 3, 9},{},{0, 1, 7},{2, 6},{1, 3},{2, 4}};

    int knightDialer(int n) {
        vector<vector<long>>dp(n+1,vector<long>(10));
        for(int j=0;j<10;j++){
            dp[1][j] = 1;
        }
        for(int i = 2; i < n+1 ;i++){
            for(int j = 0; j<10; j++){
                for(int p : path[j]){
                    dp[i][j] += dp[i-1][p];
                }
                dp[i][j] %=mod;
            }
        }
     int ans = 0;
      for(int i=0;i<10;i++){
        ans = (ans + dp[n][i]) % mod;
      }
      return ans;
    }
};