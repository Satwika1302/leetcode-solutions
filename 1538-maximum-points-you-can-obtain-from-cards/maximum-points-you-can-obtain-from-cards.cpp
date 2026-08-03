class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowsize = n-k;
        int i=0,j=0;int sum=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
        }
        cout<<sum;
        int s = 0; int mx= INT_MIN;
        if(n-k==0) return sum;
        while(j<n){
            s+=cardPoints[j];
            if(j-i+1<windowsize){
                j++;
            }else{
                cout<<sum-s<<" ";
                mx = max(mx, sum-s);
                s -= cardPoints[i];
                i++;
                j++;

            }

        }
        return mx == INT_MIN ? 0 : mx;
    }
};