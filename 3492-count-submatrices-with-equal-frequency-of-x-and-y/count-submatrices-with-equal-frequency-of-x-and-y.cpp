class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>> v(
    grid.size(),
    vector<pair<int,int>>(grid[0].size())
);

        if(grid[0][0]=='X') v[0][0]={1,0};
        else if(grid[0][0]=='Y') v[0][0]={0,1};
        else v[0][0]={0,0};

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0)continue;
            else if(i==0 || j==0){
                if(i==0){
                    if(grid[i][j]=='X') v[i][j] = {v[i][j-1].first+1,v[i][j-1].second};
                    else if(grid[i][j]=='Y') v[i][j] = {v[i][j-1].first,v[i][j-1].second+1};
                    else v[i][j] = v[i][j-1];
                }else{
                    if(grid[i][j]=='X') v[i][j] = {v[i-1][j].first+1,v[i-1][j].second};
                    else if(grid[i][j]=='Y') v[i][j] = {v[i-1][j].first,v[i-1][j].second+1};
                    else v[i][j] = v[i-1][j];
                }
            }else{
                if(grid[i][j]=='X'){
                    v[i][j].first = v[i-1][j].first+v[i][j-1].first-v[i-1][j-1].first+1;
                    v[i][j].second = v[i-1][j].second+v[i][j-1].second-v[i-1][j-1].second;
                }else if(grid[i][j]=='Y'){
                    v[i][j].first = v[i-1][j].first+v[i][j-1].first-v[i-1][j-1].first;
                    v[i][j].second = v[i-1][j].second+v[i][j-1].second-v[i-1][j-1].second+1;
                }else{
                    v[i][j].first = v[i-1][j].first+v[i][j-1].first-v[i-1][j-1].first;
                    v[i][j].second = v[i-1][j].second+v[i][j-1].second-v[i-1][j-1].second;
                }
            }
        }
    }
    int ans=0;
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(v[i][j].first > 0 && v[i][j].second > 0 && v[i][j].first == v[i][j].second) ans++;
        }

    }
    return ans;
    }
};