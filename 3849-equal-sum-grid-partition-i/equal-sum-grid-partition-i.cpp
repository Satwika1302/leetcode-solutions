class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0; 
        int m= grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+= grid[i][j];
            }
        }
        if(sum%2!=0) return false;
        long long target=sum/2;
        long long temp=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp+=grid[i][j];
                if(temp==target) return true;
            }
        }
       temp=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                temp+=grid[i][j];
                if(temp==target) return true;
            }
        }

        return false;
    }
};