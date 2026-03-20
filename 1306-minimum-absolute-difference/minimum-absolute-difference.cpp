class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int mn=INT_MAX;
        for(int i=1;i<arr.size();i++){
            mn=min(mn,arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mn){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;
    }
};