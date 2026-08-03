class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int windowSum = 0;
        int maximumSum = 0;

        unordered_map<int, int> frequency;

        for (int j = 0; j < nums.size(); j++) {
            frequency[nums[j]]++;
            windowSum += nums[j];

            while (frequency[nums[j]] > 1) {
                frequency[nums[i]]--;
                windowSum -= nums[i];

                if (frequency[nums[i]] == 0) {
                    frequency.erase(nums[i]);
                }

                i++;
            }

            maximumSum = max(maximumSum, windowSum);
        }

        return maximumSum;
    }
};