class Solution {
public:
    int getMaxLen(vector<int>& nums) {

        int positive = 0;
        int negative = 0;
        int ans = 0;

        for(int num : nums) {

            if(num > 0) {

                positive = positive + 1;

                if(negative > 0)
                    negative = negative + 1;

            }
            else if(num < 0) {

                int oldPositive = positive;
                int oldNegative = negative;

                if(oldNegative > 0)
                    positive = oldNegative + 1;
                else
                    positive = 0;

                negative = oldPositive + 1;
            }
            else {

                positive = 0;
                negative = 0;
            }

            ans = max(ans, positive);
        }

        return ans;
    }
};