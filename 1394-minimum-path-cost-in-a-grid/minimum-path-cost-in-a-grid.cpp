class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = grid[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int mn = INT_MAX;
                for (int k = 0; k < n; k++) {
                    mn = min(mn, dp[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                dp[i][j] = grid[i][j] + mn;
            }
        }

        // for(int i  = 0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};