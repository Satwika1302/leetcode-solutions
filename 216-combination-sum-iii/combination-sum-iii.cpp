class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        return combinationSum(nums,n,k);
    }

    void solve(int i,int n,int target,vector<int>& v, vector<vector<int>>& ans, vector<int>& candidates,int k){
        if(target==0 && v.size()==k){
            ans.push_back(v);
            return;
        }
        if(i==n){
            return;
        }

        if(v.size()>k){
            return;
        }

        if(target>0 && target-candidates[i]>=0){
            v.push_back(candidates[i]);
            solve(i+1,n,target-candidates[i],v,ans,candidates,k);
            v.pop_back();
        }
        solve(i+1,n,target,v,ans,candidates,k);
        
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target,int k) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(0,candidates.size(),target,v,ans,candidates,k);
        return ans;
    }
};
