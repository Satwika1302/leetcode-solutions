class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int n = arr.size();
        int count = 0;
        int sum = 0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k){
                j++;
            }else{
                int average = sum/k;
                cout<<average<<" ";
                if(average >= threshold){
                    count++;
                }
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};