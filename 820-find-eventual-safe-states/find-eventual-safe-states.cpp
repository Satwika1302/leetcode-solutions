class Solution {
public:
    bool dfs(int i,int n,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pvis,vector<int>& check){
        vis[i]=1;
        pvis[i]=1;
        check[i]=0;

        for(auto it : graph[i]){
            if(!vis[it]){
            if(dfs(it,n,graph,vis,pvis,check)==true) return true;
            }else if(pvis[it]==1){
                return true;
            }
        }
            check[i]=1;
            pvis[i]=0;
            return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n);
       vector<int>pvis(n);
        vector<int>check(n);
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,n,graph,vis,pvis,check);
            }
        }

        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};