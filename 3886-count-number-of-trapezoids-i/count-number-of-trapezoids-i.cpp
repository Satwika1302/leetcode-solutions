class Solution {
public:

    int M = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int, int> mp;

        for(auto &pt : points){
            int y = pt[1];
            mp[y]++;
        }

        long long res = 0;
        long long prevHorzLines = 0;

        for(auto &it : mp){
            long long count = it.second;  

            long long horzLines = (count * (count - 1)) / 2;  //nCn

            res += horzLines * prevHorzLines;
            res %= M;

            prevHorzLines += horzLines;
            prevHorzLines %= M;
        } 

        return res % M;
    }
};