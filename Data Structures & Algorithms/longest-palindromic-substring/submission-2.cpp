class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length of valid palindrome found: (right - 1) - (left + 1) + 1
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1; // Correct start position after loop overshoots
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);     // Odd length centers ("aba")
            expand(i, i + 1); // Even length centers ("abba")
        }

        return s.substr(start, maxLen);
    }
};