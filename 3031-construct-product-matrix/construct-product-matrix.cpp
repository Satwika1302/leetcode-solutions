class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<long long>> prefix(m,vector<long long>(n,1)),suffix(m,vector<long long>(n,1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                else if(j==0){
                    prefix[i][j] = prefix[i-1][n-1]*grid[i-1][n-1] % 12345;
                }else{
                    prefix[i][j]= prefix[i][j-1]*grid[i][j-1] % 12345;
                }
            }
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                else if(j==n-1){
                    suffix[i][j] = suffix[i+1][0] * grid[i+1][0] % 12345;
                }else{
                    suffix[i][j] = suffix[i][j+1] * grid[i][j+1] % 12345;
                }
            }
        }
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = (prefix[i][j] * suffix[i][j]) % 12345;
            }
        }
        return ans;
    }
};