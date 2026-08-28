class Solution {
public:
    void expand(string &s,int left,int right,int &start,int &mx){
        while(left>=0 && right<=s.size()-1 && s[left]==s[right]){

            int len = right-left+1;

            if(len>mx){
                mx = len;
                start = left;
            }

            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int start = 0;
        int mx = 1;

        for(int i = 0;i<s.size();i++){
            expand(s,i,i,start,mx);
            expand(s,i,i+1,start,mx);
        } 

        return s.substr(start,mx);
    }
};