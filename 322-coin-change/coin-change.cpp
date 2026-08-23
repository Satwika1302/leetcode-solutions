class Solution {
public:
    int solve(int i, int k, int n, vector<int>& coins,vector<vector<int>>& t) {
        if (k == 0)
            return 0;

        if (i == n)
            return 1e9;

        if(t[i][k]!=-1) return t[i][k];

        if (coins[i] <= k) {
            return t[i][k] = min(solve(i + 1, k, n, coins,t),
                       1 + solve(i, k - coins[i], n, coins,t));
        }
        return t[i][k] = solve(i + 1, k, n, coins,t);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>t(n+1,vector<int>(amount+1,-1));
        int ans = solve(0, amount, n, coins, t);

        return ans >= 1e9 ? -1 : ans;
    }
};