class Solution {
public:
    void solve(int i,int n,vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        solve(i+1,n,nums,v,ans);
        v.pop_back();
        solve(i+1,n,nums,v,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;int n = nums.size();
        //if(n==0) return {{}};
        vector<vector<int>>ans;
        solve(0,n,nums,v,ans);
        return ans;
    }
};