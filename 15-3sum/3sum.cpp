class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers) {
        vector<vector<int>> triplets;
        int n = numbers.size();

        sort(numbers.begin(),numbers.end());

        for(int i = 0; i < n-2; i++){
            if (numbers[i] > 0) {
                break;
            }

            if (i > 0 && numbers[i] == numbers[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                long long currSum = numbers[i] + numbers[l] + numbers[r];

                if(currSum > 0){
                    r--;
                }else if(currSum < 0){
                    l++;
                }else{
                    triplets.push_back({numbers[i], numbers[l], numbers[r]});

                    l++;
                    r--;
                    while(l<r && numbers[l]==numbers[l-1]){
                        l++;
                    }

                    while(l<r && numbers[r]==numbers[r+1]){
                        r--;
                    }
                }
            }
        }

        return triplets;
    }
};