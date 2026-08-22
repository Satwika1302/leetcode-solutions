class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int f(int m, int n, int row, int col, int maxMoves, vector<vector<vector<int>>>& dp){
        // Base Case: Successfully walked out of bounds
        if(row >= m || col >= n || row < 0 || col < 0){
            return 1;
        }
        
        // Base Case: Ran out of moves while inside the grid
        if(maxMoves == 0) return 0;
        
        // Return cached result if already calculated
        if(dp[row][col][maxMoves] != -1){
            return dp[row][col][maxMoves];
        }
        
        // Explore all 4 adjacent directions
        long long right = f(m, n, row, col + 1, maxMoves - 1, dp);
        long long left  = f(m, n, row, col - 1, maxMoves - 1, dp);
        long long up    = f(m, n, row - 1, col, maxMoves - 1, dp);
        long long down  = f(m, n, row + 1, col, maxMoves - 1, dp);

        // Store result in DP table and return
        return dp[row][col][maxMoves] = (right + left + up + down) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        // Size allocation adjusted precisely to match grid limits
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        
        ans = f(m, n, startRow, startColumn, maxMove, dp);
        return ans;
    }
};