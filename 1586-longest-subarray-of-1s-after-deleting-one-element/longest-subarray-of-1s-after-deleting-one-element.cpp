class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int zeroes=0;
        int mx=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) zeroes++;
            while(zeroes>1){
                if(nums[i]==0){
                zeroes--;
                }
                i++;
            }
            
            mx = max(mx,j-i+1);
            cout<<i<<" "<<j<<" "<<mx<<endl;
            //cout<<mx<<" ";
            j++;
        }
        return mx-1;
    }
};