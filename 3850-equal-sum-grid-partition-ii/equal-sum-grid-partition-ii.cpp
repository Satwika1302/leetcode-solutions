class Solution {
public:
    typedef long long ll;

    bool solve(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();

        unordered_map<int,int> bmp, tmp;
        ll bsum = 0, tsum = 0;

        // Step 1: total sum + bottom freq
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bsum += grid[i][j];
                bmp[grid[i][j]]++;
            }
        }

        // Step 2: move row by row
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                bsum -= grid[i][j];
                bmp[grid[i][j]]--;

                tsum += grid[i][j];
                tmp[grid[i][j]]++;
            }

            // Case 1: equal
            if(tsum == bsum) return true;

            // Case 2: remove from top
            ll tdiff = tsum - bsum;
            if(tdiff > 0 && tdiff <= 100000){
                int h = i + 1, w = n;

                if(h > 1 && w > 1){
                    if(tmp[tdiff] > 0) return true;
                }
                else if(h > 1 && w == 1){
                    if(grid[0][0] == tdiff || grid[i][0] == tdiff) return true;
                }
                else if(h == 1 && w > 1){
                    if(grid[0][0] == tdiff || grid[0][n-1] == tdiff) return true;
                }
            }

            // Case 3: remove from bottom
            ll bdiff = bsum - tsum;
            if(bdiff > 0){
                int h = m - i - 1, w = n;

                if(h > 1 && w > 1){
                    if(bmp[bdiff] > 0 && bdiff <= 100000) return true;
                }
                else if(h > 1 && w == 1){
                    if(grid[i+1][0] == bdiff || grid[m-1][0] == bdiff) return true;
                }
                else if(h == 1 && w > 1){
                    if(grid[m-1][0] == bdiff || grid[m-1][n-1] == bdiff) return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid)) return true;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[j][i] = grid[i][j];
            }
        }

        return solve(mat);
    }
};