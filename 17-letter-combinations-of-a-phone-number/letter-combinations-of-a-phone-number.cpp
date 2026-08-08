class Solution {
public:
    void solve(int i,int n,string str,vector<string>& ans,unordered_map<int,vector<char>>& mp, string& digits){
        
        if(i==n){
            ans.push_back(str);
            return;
        }

        if(i>n){
            return;
        }
        cout<<i<<" "<<str<<endl;
        for(auto it : mp[digits[i] - '0']){
            string op = str + it;
            solve(i+1,n,op,ans,mp,digits);
        }

        return;

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp;

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        string str = "";
        vector<string>ans;
        solve(0,digits.size(),str,ans,mp,digits);
      return ans;
    }
};