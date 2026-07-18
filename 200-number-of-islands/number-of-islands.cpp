class Solution {
public:
    void islands(vector<vector<char>>& grid,
                 vector<vector<int>>& vis,
                 int sr,
                 int sc) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        int nr[] = {0, -1, 0, 1};
        int nc[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + nr[i];
                int c = col + nc[i];

                if (r >= 0 && r < n &&
                    c >= 0 && c < m &&
                    grid[r][c] == '1' &&
                    vis[r][c] == 0) {

                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    islands(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
};