class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        int cnt = mp.size();
        int i=0,j=0;
        while(j<s2.size()){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0){
                    cnt--;
                }
            }
            if(j-i+1<s1.size()){
                j++;
            }else{
                if(cnt==0){
                    return true;
                }
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1){
                    cnt++;
                  }
                }
                
                i++;
                j++;
            
        }
        }
        return false;
    }
};