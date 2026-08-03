class Solution {
private:
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }

        int i = 0;
        int sum = 0;
        int count = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            count += j - i + 1;
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal)
             - countAtMost(nums, goal - 1);
    }
};