class Solution {
public:
    void solve(int n, string temp, vector<string>& v) {

        if (n == 0) {
            v.push_back(temp);
            return;
        }

        for (int i = 0; i < 3; i++) {
            char ch = 'a' + i;
            if (temp.size() > 0 && temp.back() == ch) {
                continue;
            }
            solve(n - 1, temp + ch, v);
        }
    }
    string getHappyString(int n, int k) {
        string ans;
        vector<string> v;
        solve(n, "", v);
        if (k > v.size()) {
            return "";
        }
        return v[k - 1];
    }
};