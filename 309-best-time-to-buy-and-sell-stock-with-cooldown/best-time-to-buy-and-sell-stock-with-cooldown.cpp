class Solution {
public:
    int profit(int i,bool buy,vector<int>& prices,int n,vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max( -prices[i]+profit(i+1,0,prices,n,dp) , 0 + profit(i+1,1,prices,n,dp));
        }
        return  dp[i][buy] = max(prices[i]+profit(i+2,1,prices,n,dp) , 0 + profit(i+1,0,prices,n,dp));
 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profit(0,1,prices,n,dp);
    }
};