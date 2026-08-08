class Solution {
public:

    void solve(int i, int n, int target,
               vector<int>& v,
               vector<vector<int>>& ans,
               vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (i == n || target < 0) {
            return;
        }

        // ----------------
        // TAKE
        // ----------------
        if (candidates[i] <= target) {

            v.push_back(candidates[i]);

            solve(i + 1,
                  n,
                  target - candidates[i],
                  v,
                  ans,
                  candidates);

            v.pop_back();
        }


        // ----------------
        // NOT TAKE
        // ----------------

        int next = i + 1;

        // skip duplicates
        while (next < n &&
               candidates[next] == candidates[i]) {

            next++;
        }

        solve(next,
              n,
              target,
              v,
              ans,
              candidates);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        solve(0,
              candidates.size(),
              target,
              v,
              ans,
              candidates);

        return ans;
    }
};