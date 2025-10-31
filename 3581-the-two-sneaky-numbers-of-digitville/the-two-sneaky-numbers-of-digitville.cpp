class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;vector<int>ans;
        for(int k : nums){
            mp[k]++;
            if(mp[k]==2)ans.push_back(k);
        }
        return ans;
    }
};