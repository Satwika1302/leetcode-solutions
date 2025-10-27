class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1')cnt++;
            }
            if(cnt!=0)v.push_back(cnt);
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        int ans=0;int n=v.size();
        if(n==1) return 0;
        for(int i=0;i<n-1;i++){
            ans+=v[i]*v[i+1];
        }
        return ans;
    }
};