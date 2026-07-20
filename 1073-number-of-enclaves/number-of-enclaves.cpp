class Solution {
public:
    void dfs(vector<vector<int>>& board,vector<vector<int>> &vis,int row,int col){
        int n = board.size();
        int m = board[0].size();
        vis[row][col]=1;
        int nr[] = {0,-1,0,1};
        int nc[] = {-1,0,1,0};
        for(int i=0;i<4;i++){
            int r = row + nr[i];
            int c = col + nc[i];
            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && board[r][c]==1){
                dfs(board,vis,r,c);
            }
        }
        return;
    }


    int numEnclaves(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans =0;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]==1 && !vis[i][j]){
                    dfs(board,vis,i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
