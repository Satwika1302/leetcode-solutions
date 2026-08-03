class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int n = s.size();
        int wcount=0; int mx=0;
        while(j<n){
            wcount+=abs(s[j]-t[j]);
            while(wcount>maxCost){
                wcount-=abs(s[i]-t[i]);
                i++;
            }
            mx = max(mx,j-i+1);
            j++; 
        }
        return mx;
    }
};