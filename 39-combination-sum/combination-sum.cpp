class Solution {
public:
    void solve(int i,int n,int target,vector<int>& v, vector<vector<int>>& ans, vector<int>& candidates){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==n){
            return;
        }

        if(target>0 && target-candidates[i]>=0){
            v.push_back(candidates[i]);
            solve(i,n,target-candidates[i],v,ans,candidates);
            v.pop_back();
        }
        solve(i+1,n,target,v,ans,candidates);
        
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(0,candidates.size(),target,v,ans,candidates);
        return ans;
    }
};