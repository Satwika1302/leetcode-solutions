class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int mx = INT_MIN;
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
           
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
        
            mx = max(mx,j-i+1); 
            j++;
        
        }
        return mx == INT_MIN ? 0 : mx;
    }
};