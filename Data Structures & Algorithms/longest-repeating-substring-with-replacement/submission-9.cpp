#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> freq(26, 0); // Frequency table for uppercase English letters
        int l = 0;
        int maxFreq = 0; // Stores the highest frequency of any single character in the CURRENT window
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            // Include the current character in the window frequency
            freq[s[r] - 'A']++;
            
            // Update the maximum frequency found in the current window
            maxFreq = std::max(maxFreq, freq[s[r] - 'A']);

            // Current window size is (r - l + 1)
            // Number of replacements needed is: window size - maxFreq
            // If replacements needed exceed k, the window is invalid. Shrink it!
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            // Update the maximum length found so far
            maxLen = std::max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
