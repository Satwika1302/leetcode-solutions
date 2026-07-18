class Solution {
public:
    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color
    ) {
        int n = image.size();
        int m = image[0].size();

        int k = image[sr][sc];

        if (k == color) {
            return image;
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        vis[sr][sc] = 1;

        int nr[] = {0, -1, 0, 1};
        int nc[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            image[r][c] = color;

            for (int i = 0; i < 4; i++) {
                int row = r + nr[i];
                int col = c + nc[i];

                if (row >= 0 && row < n &&
                    col >= 0 && col < m &&
                    image[row][col] == k &&
                    !vis[row][col]) {

                    vis[row][col] = 1;
                    q.push({row, col});
                }
            }
        }

        return image;
    }
};