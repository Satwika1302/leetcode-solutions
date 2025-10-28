class Solution {
public:
    bool isValid(vector<int>& nums, int k, bool right) {
        vector<int> v = nums; int n=nums.size();
        while (k >= 0 && k < n) {
            if (right && v[k] == 0) {
                k++;
            } else if (!right && v[k] == 0) {
                k--;
            }
            if (k < 0 || k >= n)
                break;
            if (v[k] > 0) {
                v[k] -= 1;
                right = !right;
                if (right)
                    k++;
                else
                    k--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0)
                cnt++;
        }
        if (cnt == n)
            return true;
        else
            return false;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, i, true)) ans++;
                if (isValid(nums, i, false)) ans++;
            }
        }

        return ans;
    }
};