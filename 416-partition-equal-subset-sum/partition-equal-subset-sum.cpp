class Solution {
public:
    bool subsetsum(vector<int>& nums,int target){
        int n = nums.size();
        vector<vector<int>> t(n+1,vector<int>(target+1,0));
        for(int i=0;i<target+1;i++)
            t[0][i]=0;                                         
        for(int i=0;i<n+1;i++)
            t[i][0]=1;  

       for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
                t[i][j] = (t[i-1][j-nums[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][target];    
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int k: nums){
            sum+=k;
        }
        if(sum%2!=0) return false;
        return subsetsum(nums,sum/2);
    }
};