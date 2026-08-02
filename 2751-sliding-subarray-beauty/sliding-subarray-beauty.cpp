class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        vector<int> ans;
        vector<int> freq(51, 0);

        while (j < n) {
            // Store negative numbers using their absolute value
            if (nums[j] < 0) {
                freq[-nums[j]]++;
            }

            // Window is not complete yet
            if (j - i + 1 < k) {
                j++;
            }
            // Complete window of size k
            else {
                int count = 0;
                int beauty = 0;

                // -50, -49, ..., -1
                for (int value = 50; value >= 1; value--) {
                    count += freq[value];

                    if (count >= x) {
                        beauty = -value;
                        break;
                    }
                }

                ans.push_back(beauty);

                // Remove the left element
                if (nums[i] < 0) {
                    freq[-nums[i]]--;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};