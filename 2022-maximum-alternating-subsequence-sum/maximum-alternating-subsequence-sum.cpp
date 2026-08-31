class Solution {
public:
    long long solve(int i,bool pos,vector<int>& nums,int n, vector<vector<long long>> &dp){
        if(i==n) return 0;
        if(dp[i][pos]!=-1) return dp[i][pos];
        if(pos){
            return dp[i][pos]=max(nums[i]+solve(i+1,0,nums,n,dp),solve(i+1,1,nums,n,dp));
        }
        return dp[i][pos]=max(-nums[i]+solve(i+1,1,nums,n,dp), solve(i+1,0,nums,n,dp));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0,1,nums,n,dp);
    }
};