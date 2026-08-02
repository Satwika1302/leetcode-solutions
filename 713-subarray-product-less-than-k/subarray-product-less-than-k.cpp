class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int cnt = 0;
        int p = 1;
        while(j<nums.size()){
            p *= nums[j];
            while(i<nums.size() && p >= k){
                p = p / nums[i];
                i++;
            }
            
            cnt+=(j-i+1);
            cout<<p<<" "<<cnt<<" "<<endl;
            j++;
        }
        return cnt;
    }
};