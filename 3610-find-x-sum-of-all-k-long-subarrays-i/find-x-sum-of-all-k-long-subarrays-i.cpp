class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int left =0;
        map<int,int>mp;
        vector<int>ans;
        for(int right=0;right<nums.size();right++)
        {
             mp[nums[right]]++;
            if(right-left+1==k)
            {
                priority_queue<pair<int,int>>q;
                for(auto it : mp)
                {
                    q.push({it.second,it.first});
                }
                int sum=0;
                for(int i=0;i<x && !q.empty();i++)
                {
                    int temp = q.top().second*q.top().first;
                    q.pop();
                    sum+=temp;
                }
                ans.push_back(sum);
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};