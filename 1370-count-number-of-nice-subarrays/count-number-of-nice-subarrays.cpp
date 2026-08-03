class Solution {
private:
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }

        int i = 0;
        int oddCount = 0;
        int answer = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 1) {
                oddCount++;
            }

            while (oddCount > goal) {
                if (nums[i] % 2 == 1) {
                    oddCount--;
                }

                i++;
            }

            answer += j - i + 1;
        }

        return answer;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k)
             - countAtMost(nums, k - 1);
    }
};