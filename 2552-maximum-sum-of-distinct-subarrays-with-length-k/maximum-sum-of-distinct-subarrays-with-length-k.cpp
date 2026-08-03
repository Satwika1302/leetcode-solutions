class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        long long windowSum = 0;
        long long maximumSum = 0;

        unordered_map<int, int> frequency;

        while (j < n) {
            frequency[nums[j]]++;
            windowSum += nums[j];

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                if (frequency.size() == k) {
                    maximumSum = max(maximumSum, windowSum);
                }

                frequency[nums[i]]--;
                windowSum -= nums[i];

                if (frequency[nums[i]] == 0) {
                    frequency.erase(nums[i]);
                }

                i++;
                j++;
            }
        }

        return maximumSum;
    }
};