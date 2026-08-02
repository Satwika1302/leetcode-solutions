class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0, r= nums.size()-1;
        vector<int> res(nums.size(), 0);
        for(int k= nums.size() - 1 ;k>=0;k--){
            if(abs(nums[l])<abs(nums[r])) {
            res[k] = nums[r] * nums[r];
            r--;
            }else{
                res[k]=nums[l]*nums[l];
                l++;
            }
        }
        return res;
    }
};