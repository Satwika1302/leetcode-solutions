class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int cnt=target[0];
        for(int i=1;i<target.size();i++){
            if(target[i]>target[i-1])cnt+=target[i]-target[i-1];
            else continue;
        }
        return cnt;
    }
};