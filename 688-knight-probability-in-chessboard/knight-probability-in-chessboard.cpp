class Solution {
public:
    double solve(int k, int r,int c,int n,vector<vector<vector<double>>>& dp){
        if(r<0 || r>n-1 || c<0 || c>n-1 ){
            return 0.0;
        }
        if(k==0) return 1.0;
        if(dp[k][r][c]!=-1.0) return dp[k][r][c];
        double s = 0.0;
        int dr[] = {-2,-2,-1,-1,1,1,2,2};
        int dc[] = {-1,1,-2,2,-2,2,-1,1};
        for(int i=0;i<8;i++){
            int row = r + dr[i];
            int col = c + dc[i];
            double p =  solve(k-1,row,col,n,dp)/8.0;
            s += p;
        }
        return dp[k][r][c]=s;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,-1.0)));
        return solve(k,row,column,n,dp);
    }
};