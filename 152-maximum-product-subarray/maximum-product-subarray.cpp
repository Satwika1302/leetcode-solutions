class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxp=nums[0],minp=nums[0],ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxp,minp);
            maxp=max(maxp*nums[i],nums[i]);
            minp=min(minp*nums[i], nums[i]);
            cout<<maxp<<" "<<minp<<" ";
            ans= max(ans,maxp);
            cout<<ans<<endl;
        }
        return ans;
    }
};