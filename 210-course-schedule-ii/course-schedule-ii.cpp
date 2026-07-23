class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        queue<int>q;
        vector<int>topo;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int k = q.front();
            q.pop();
            topo.push_back(k);
            for(auto it: graph[k]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            } 
        }
        if(topo.size()!= numCourses) return {};
        return topo; 
    }
};

