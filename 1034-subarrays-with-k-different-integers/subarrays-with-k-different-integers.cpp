class Solution {
private:
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }

        int i = 0;
        unordered_map<int,int>mp;
        int answer = 0;

        for (int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            
            while (mp.size() > goal) {
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }

                i++;
            }

            answer += j - i + 1;
        }

        return answer;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMost(nums, k)
             - countAtMost(nums, k - 1);
    }
};
