class Solution {
public:
    void check(int i,int n ,string str, vector<string>& ans,string s){
        if(i==n){
            ans.push_back(str);
            return;
        }

        if(isdigit(s[i])){
            check(i+1,n,str+s[i],ans,s);
        }else{
            char ch1 = tolower(s[i]);
            char ch2 = toupper(s[i]);
            check(i+1,n,str+ch1,ans,s);
            check(i+1,n,str+ch2,ans,s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string str = "";
        check(0,s.length(),str,ans,s);
        return ans;
    }
};