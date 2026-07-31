class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(mp.size()==0 || mp.find(diff)==mp.end()){
                mp[nums[i]]=i;
            }else{
                return {i,mp[diff]};
            }
        }
        return {0,0};
    }
};