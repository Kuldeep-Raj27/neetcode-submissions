class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> check;
        int maxlen =0;
        int l=0;
        if(s.size()==0){
            return 0;
        }
        check[s[l]]=0;
        for(int r=1;r<s.size();r++){
            if(check.count(s[r]) && (check[s[r]]>=l)){
                maxlen = ((r-l)>maxlen)?(r-l):maxlen;
                l = check[s[r]]+1;
                check[s[r]] = r;
            }
            else{
                check[s[r]] = r;
            }
        }
        if((s.size()-l)>maxlen){
            return s.size()-l;
        }
        return maxlen;
    }
};
