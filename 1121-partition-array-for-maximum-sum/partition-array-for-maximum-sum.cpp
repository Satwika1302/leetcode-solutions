class Solution {
public:
    int solve(int i,vector<int>& arr,int k,int n, vector<int>& dp){
        if(i==n) return 0;
        int mx = 0;
        int ans = 0;
        if(dp[i]!=-1) return dp[i];
        for(int j = i;j<min(n,i+k);j++){
            mx = max(mx,arr[j]);
            int len = j-i+1;
            int curr = mx * len + solve(j+1,arr,k,n,dp);
            ans = max(curr,ans);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
         vector<int> dp(n,-1);
        return solve(0,arr,k,n,dp);
    }
};