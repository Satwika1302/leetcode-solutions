class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // result matrix of size (m-k+1) x (n-k+1)
        vector<vector<int>> v(m - k + 1, vector<int>(n - k + 1));

        // iterate over all possible k x k submatrices
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                // use set to store unique elements in sorted order
                set<int> s;

                // collect elements of current k x k submatrix
                for (int p = i; p < i + k; p++) {
                    for (int q = j; q < j + k; q++) {
                        s.insert(grid[p][q]); // removes duplicates automatically
                    }
                }

                // convert set to vector for easy traversal
                vector<int> arr(s.begin(), s.end());

                int mn = INT_MAX;

                // compute minimum difference between adjacent elements
                if (arr.size() >= 2) {
                    for (int x = 1; x < arr.size(); x++) {
                        mn = min(mn, arr[x] - arr[x - 1]); // sorted, so no abs needed
                    }
                } else {
                    // if less than 2 unique elements, no valid pair
                    mn = 0;
                }

                // store result
                v[i][j] = mn;
            }
        }

        return v;
    }
};