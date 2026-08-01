class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes=0,ones=0,twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroes++;
            else if(nums[i]==1) ones++;
            else twos++;
        }
        cout<<zeroes<<" "<<ones<<" "<<twos<<endl;
        int k=0;
        while(k<zeroes){
            cout<<k<<" ";
            nums[k]=0;
            
            k++;
        }
        while(k<zeroes+ones){
            cout<<k<<" ";
            nums[k]=1;
            k++;
        }
        while(k<nums.size()){
            cout<<k<<" ";
            nums[k]=2;
            k++;
        }
    }
};