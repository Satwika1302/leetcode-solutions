// SAY: I'll keep the solution in the interface provided by the problem.
class Solution {
public:
    // SAY: This helper expands around a candidate center and updates the best palindrome.
    void expand(const string& s, int left, int right, int& bestStart, int& bestLen) {
        // SAY: I keep expanding while both indices are valid and the characters match.
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
            // SAY: If this palindrome is longer than the best one, I save its start and length.
            if (right - left + 1 > bestLen) {
                // SAY: The current left boundary becomes the best starting position.
                bestStart = left;
                // SAY: And this inclusive interval gives me the new best length.
                bestLen = right - left + 1;
            }
            // SAY: Now I expand one position farther on each side.
            --left;
            // SAY: I move the right boundary outward as well.
            ++right;
        }
    }

    // SAY: This function returns the longest palindromic substring.
    string longestPalindrome(string s) {
        // SAY: I'll initialize the first character as the best palindrome.
        int bestStart = 0;
        // SAY: Since the input is nonempty, the initial best length is one.
        int bestLen = 1;

        // SAY: I'll consider every position as a possible palindrome center.
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            // SAY: First I handle odd-length palindromes centered directly on this character.
            expand(s, i, i, bestStart, bestLen);
            // SAY: Then I handle even-length palindromes centered between this character and the next.
            expand(s, i, i + 1, bestStart, bestLen);
        }

        // SAY: Finally, I return the substring represented by the best boundaries I found.
        return s.substr(bestStart, bestLen);
    }
};
