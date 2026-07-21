class Solution {
public:
    bool dfs(int node, int col,
             vector<vector<int>>& graph,
             vector<int>& color) {
        
        color[node] = col;

        for (int neighbor : graph[node]) {
            
            // Neighbor has not been colored yet
            if (color[neighbor] == -1) {
                
                // Give it the opposite color
                if (!dfs(neighbor, 1 - col, graph, color)) {
                    return false;
                }
            }
            
            // Neighbor already has the same color
            else if (color[neighbor] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1 means uncolored
        vector<int> color(n, -1);

        // The graph may contain multiple disconnected components
        for (int node = 0; node < n; node++) {
            
            if (color[node] == -1) {
                if (!dfs(node, 0, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};


// class Solution {
// public:
//     bool check(vector<vector<int>>& graph,vector<int>& color,int i, int n){
//         queue<int>q;
//         q.push(i);
//         color[i]=0;
//         while(!q.empty()){
//             int k = q.front();
//             q.pop();
//             for(auto it : graph[k]){
//                 if(color[it]==-1){
//                     color[it]=!color[k];
//                     q.push(it);
//                 }else if(color[it]==color[k]){
//                     return false;
//                 }
//             }
            
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int>color(n,-1);
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//             if(check(graph,color,i,n)==false){
//                 return false;
//             }
//             }
//         }
//         return true;

//     }
// };