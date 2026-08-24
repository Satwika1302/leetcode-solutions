class Solution {
public:
void lcs(string text1, string text2, vector<vector<int>>& dp){
     int m = text1.size();
        int n = text2.size();
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return ;
}
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        lcs(str1,str2,dp);
        int i = m,j=n;
        vector<char>v;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                v.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    v.push_back(str1[i-1]);
                    i--;
                }else{
                    v.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            v.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            v.push_back(str2[j-1]);
            j--;
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(char ch : v){
            ans += ch;
        }
    return ans;
    }
};