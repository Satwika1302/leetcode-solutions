class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int t1=x,t2=y,b1=x+k-1;
        while(t1<b1){
            for(t2=y;t2<y+k;t2++){
                swap(grid[t1][t2],grid[b1][t2]);
            }
            t1++;
            b1--;
        }
        return grid;
    }
};