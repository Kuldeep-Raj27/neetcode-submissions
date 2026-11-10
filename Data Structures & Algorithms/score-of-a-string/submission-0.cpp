class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
        char prev=s[0];
        for(char c:s){
            score += abs(prev-c);
            prev =c;
        }
        return score;
        
    }
};