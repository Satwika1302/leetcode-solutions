class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return effort;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int maxeffort = max(effort,abs(heights[nr][nc]-heights[r][c]));
                    if(dist[nr][nc]>maxeffort){
                        dist[nr][nc] = maxeffort;
                        pq.push({maxeffort,{nr,nc}});
                    }
                }
            }
        }

     return 0;
    }
};