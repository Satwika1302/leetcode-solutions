class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = n-2 ; i >= 0 ;i--){
            for(int j = 0 ; j < n; j++){
                int dl,dr;
                if(j==0){
                    dl=INT_MAX;
                    dr=matrix[i+1][j+1];
                }else if(j==n-1){
                    dl=matrix[i+1][j-1];
                    dr = INT_MAX;
                }else{
                    dl=matrix[i+1][j-1];
                    dr=matrix[i+1][j+1];
                }
                int mn = min(dl,dr);
                matrix[i][j] += min(matrix[i+1][j] , mn);
                //cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
            }
        }
        int ans = matrix[0][0];
        for(int j=1; j<n; j++){
            ans = min(ans, matrix[0][j]);
        }
        return ans;
    }
};