class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&vis, int i){
        vis[i]=1;
        for(int k : adj[i]){
            if(!vis[k]){
                dfs(adj,vis,k);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt=0;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        // for(int i=0;i<n+1;i++){
        //     cout<<vis[i]<<" ";
        // }
    return cnt;
    }
};