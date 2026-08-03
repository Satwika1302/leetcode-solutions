class Solution {
public:
    int maxSatisfied(
        vector<int>& customers,
        vector<int>& grumpy,
        int minutes
    ) {
        int n = customers.size();

        int alreadySatisfied = 0;

        for (int index = 0; index < n; index++) {
            if (grumpy[index] == 0) {
                alreadySatisfied += customers[index];
            }
        }

        int i = 0;
        int j = 0;

        int extraSatisfied = 0;
        int maximumExtra = 0;

        while (j < n) {
            // Only grumpy customers become additionally satisfied
            if (grumpy[j] == 1) {
                extraSatisfied += customers[j];
            }

            if (j - i + 1 < minutes) {
                j++;
            }
            else if (j - i + 1 == minutes) {
                maximumExtra = max(
                    maximumExtra,
                    extraSatisfied
                );

                if (grumpy[i] == 1) {
                    extraSatisfied -= customers[i];
                }

                i++;
                j++;
            }
        }

        return alreadySatisfied + maximumExtra;
    }
};