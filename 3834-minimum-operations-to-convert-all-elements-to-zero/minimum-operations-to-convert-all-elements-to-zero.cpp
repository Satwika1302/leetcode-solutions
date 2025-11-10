class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int cnt=0;
        for(int k : nums){
            while(!st.empty() && st.top()>k){
                st.pop();
            }
            if(k==0)continue;
            if(st.empty() || st.top()<k){
                st.push(k);
                cnt++;
            }
        }
        return cnt;
    }
};