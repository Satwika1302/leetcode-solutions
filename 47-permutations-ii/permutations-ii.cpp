class Solution {
public:

        void solve(vector<int>& nums,
               vector<int>& current,
               vector<bool>& used,
               set<vector<int>>& s) {

        // Base case
        if(current.size() == nums.size()) {
            s.insert(current);
            return;
        }

        // Try every number for the current position
        for(int i = 0; i < nums.size(); i++) {

            // Already used in current permutation
            if(used[i])
                continue;

            // CHOOSE
            current.push_back(nums[i]);
            used[i] = true;

            // EXPLORE
            solve(nums, current, used, s);

            // UNDO / BACKTRACK
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        set<vector<int>>s;
        vector<bool> used(nums.size(), false);

        solve(nums, current, used, s);
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};

// class Solution {
// public:

//     void solve(vector<int>& nums,
//                vector<int>& current,
//                vector<bool>& used,
//                vector<vector<int>>& ans) {

//         // Base case
//         if(current.size() == nums.size()) {
//             ans.push_back(current);
//             return;
//         }

//         // Try every number for the current position
//         for(int i = 0; i < nums.size(); i++) {

//             // Already used in current permutation
//             if(used[i])
//                 continue;

//             // CHOOSE
//             current.push_back(nums[i]);
//             used[i] = true;

//             // EXPLORE
//             solve(nums, current, used, ans);

//             // UNDO / BACKTRACK
//             current.pop_back();
//             used[i] = false;
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {

//         vector<vector<int>> ans;
//         vector<int> current;
//         vector<bool> used(nums.size(), false);

//         solve(nums, current, used, ans);

//         return ans;
//     }
// };