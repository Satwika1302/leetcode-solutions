class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
    //store prefix sum in grid
    int ans = (grid[0][0] <= k)? 1:0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0)continue;
            else if(i==0)grid[i][j]+=grid[i][j-1];
            else if(j==0)grid[i][j]+=grid[i-1][j];
            else grid[i][j] = grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+grid[i][j];

            if(grid[i][j]<=k) ans++;
        }
    }

     return ans;
    }
};