class Solution {
public:

    int solve(int target, vector<int>& nums, vector<int>& t) {

        if (target == 0) {
            return 1;
        }

        if(t[target]!=-1){
            return t[target];
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] <= target) {

                count += solve(target - nums[i], nums,t);
            }
        }

        return t[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>t(target+1,-1);
        return solve(target, nums,t);
    }
};