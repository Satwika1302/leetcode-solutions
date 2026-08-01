class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int p1=0,p2=0;
        vector<vector<int>> ans;
        while(p1<n1 && p2<n2){
            if(nums1[p1][0]==nums2[p2][0]){
                ans.push_back({nums1[p1][0],nums1[p1][1]+nums2[p2][1]});
                p1++;
                p2++;
            }else if(nums1[p1][0]>nums2[p2][0]){
                ans.push_back({nums2[p2][0],nums2[p2][1]});
                p2++;
            }else{
                ans.push_back({nums1[p1][0],nums1[p1][1]});
                p1++;
            }
        }
        while(p1<n1){
            ans.push_back({nums1[p1][0],nums1[p1][1]});
            p1++;
        }
        while(p2<n2){
            ans.push_back({nums2[p2][0],nums2[p2][1]});
            p2++;
        }
        return ans;
    }
};