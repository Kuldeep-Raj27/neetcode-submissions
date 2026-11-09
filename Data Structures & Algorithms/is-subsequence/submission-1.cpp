class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int len = s.size();
        int lent = t.size();
        int i=0,j=0;
        for(;i<len;i++){
            // s[i];
            while(j<lent && s[i]!=t[j] ){
                j++;
            }
            if(j>=lent){
                return false;
                break;
            }
j++;
        }
        return true;

    }
};