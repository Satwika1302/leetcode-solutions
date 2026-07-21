class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int>& color,int i, int n){
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto it : graph[k]){
                if(color[it]==-1){
                    color[it]=!color[k];
                    q.push(it);
                }else if(color[it]==color[k]){
                    return false;
                }
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(check(graph,color,i,n)==false){
                return false;
            }
            }
        }
        return true;

    }
};