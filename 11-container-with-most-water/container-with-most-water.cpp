class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximumarea = INT_MIN;
        int n = height.size();
        int l=0,r=n-1;

        while(l<r){

            int curarea = (r-l) * (min(height[l],height[r]));
            maximumarea = max(maximumarea, curarea);

        if(height[l]<height[r]){
            l++;
        }else{
            r--;
        }

        }
        return maximumarea;
    }
};