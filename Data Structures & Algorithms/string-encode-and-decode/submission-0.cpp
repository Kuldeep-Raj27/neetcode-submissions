class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for (const string& str : strs) {
            s += to_string(str.size());   // convert length to string
            s += '#';
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            // Find the position of '#'
            int j = i;
            while (j < s.size() && s[j] != '#') {
                j++;
            }
            // Extract the length (digits from i to j-1)
            string lenStr = s.substr(i, j - i);
            int length = stoi(lenStr);     // convert to int

            // Extract the actual string
            int start = j + 1;
            string word = s.substr(start, length);
            result.push_back(word);

            // Move to the next segment
            i = start + length;
        }
        return result;
    }
};