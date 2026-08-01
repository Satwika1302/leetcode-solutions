class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // Add numbers smaller than pivot
        for (int num : nums) {
            if (num < pivot) {
                ans.push_back(num);
            }
        }

        // Add numbers equal to pivot
        for (int num : nums) {
            if (num == pivot) {
                ans.push_back(num);
            }
        }

        // Add numbers greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};