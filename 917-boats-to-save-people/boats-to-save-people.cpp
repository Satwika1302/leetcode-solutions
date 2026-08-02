class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0;
        int r = people.size() - 1;
        int boatCount = 0;

        while (l <= r) {
            // Try pairing the lightest with the heaviest
            if (people[l] + people[r] <= limit) {
                l++;
            }

            // The heaviest person always takes a boat
            r--;
            boatCount++;
        }

        return boatCount;
    }
};