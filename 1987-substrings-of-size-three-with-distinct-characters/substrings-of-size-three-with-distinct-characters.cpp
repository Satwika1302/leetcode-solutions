class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0;
        int cnt=0;
        unordered_map<int,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(j-i+1<3){
             j++;
            }else{
                if(mp.size()==3){
                    cnt++;
                }
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                        cout<<s[i]<<" ";
                    }
                
                i++;j++;
            }
        }
        return cnt;
    }
};