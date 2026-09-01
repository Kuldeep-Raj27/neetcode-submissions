class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i=0, j=len-1;
        bool ans = true;
        while(i<j){
            bool mouse = false;
            if(!isalnum(static_cast<unsigned char>(s[i]))){
                i++;
                mouse = true;
            }
            if(!isalnum(static_cast<unsigned char>(s[j]))){
                j--;
                mouse = true;
            }
            if(mouse){
                continue;
            }

            if(tolower(s[i]) != tolower(s[j]) ){
                ans = false;
                break;
            }
            i++;
            j--;


        }
        return ans;
    }
};
