class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;

        unordered_map<char,int>mp;
        for(char ch : p){
            mp[ch]++;
        }
        int cnt = mp.size();
        vector<int>v;
        int curr=i;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt--;
                }
            }
            if(j-i+1<p.size()){
                j++;
            }else{
                if(cnt==0){
                    v.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return v;
    }
};