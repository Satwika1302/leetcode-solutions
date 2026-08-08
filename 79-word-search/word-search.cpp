class Solution {
public:

    bool solve(int i, int j, int k,
               vector<vector<char>>& board,
               string& word) {

        int m = board.size();
        int n = board[0].size();

        // Out of bounds
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        // Current character does not match
        if (board[i][j] != word[k])
            return false;

        // Entire word matched
        if (k == word.size() - 1)
            return true;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            solve(i + 1, j, k + 1, board, word) ||
            solve(i - 1, j, k + 1, board, word) ||
            solve(i, j + 1, k + 1, board, word) ||
            solve(i, j - 1, k + 1, board, word);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Every cell can potentially be the starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};