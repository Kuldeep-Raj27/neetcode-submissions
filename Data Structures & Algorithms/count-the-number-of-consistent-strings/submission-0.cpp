class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        unordered_set<char> s;
        for(char j:allowed){
            s.insert(j);
        }

        for(auto word:words){
            bool check= true;
            
            for(char c:word){
                if(!s.contains(c)){
                    check = false;
                    break;
                }
            }
            if(check) ans++;
        }
        return ans;
    }
};