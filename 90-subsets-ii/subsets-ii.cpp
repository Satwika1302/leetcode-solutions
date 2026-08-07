class Solution {
public:
    void solve(int i,int n,vector<int>& nums, vector<int>& v, set<vector<int>>& s){
        if(i==n){
            s.insert(v);
            return;
        }
        v.push_back(nums[i]);
        solve(i+1,n,nums,v,s);
        v.pop_back();
        solve(i+1,n,nums,v,s);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;int n = nums.size();
        sort(nums.begin(),nums.end());
        //if(n==0) return {{}};
        vector<vector<int>>ans;
        set<vector<int>>s;
        solve(0,n,nums,v,s);
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};