class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(); set<int>s;
        int n=grid[0].size();
        vector<vector<int>> v((m-k+1),vector<int>(n-k+1));
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                set<int> s;  

                for (int p = i; p < i + k; p++) {
                    for (int q = j; q < j + k; q++) {
                        s.insert(grid[p][q]);
                    }
                }

            
                vector<int> arr(s.begin(), s.end());

                int mn = INT_MAX;

                if (arr.size() >= 2) {
                    for (int x = 1; x < arr.size(); x++) {
                        mn = min(mn, arr[x] - arr[x - 1]);
                    }
                } else {
                    mn = 0; 
                }

                v[i][j] = mn;
            }
        }

        return v;
    }
};