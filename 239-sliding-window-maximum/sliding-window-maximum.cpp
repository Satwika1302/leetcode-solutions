class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i=0,j=0;
        int n = arr.size();
        list<int> l;
        vector<int>v;
        while(j<n){
            while(l.size()> 0 && l.back()<arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                v.push_back(l.front());
            
            if(l.front()==arr[i]){
                l.pop_front();
            }
            i++;
            j++;
            }
        }
        return v;
    }
};