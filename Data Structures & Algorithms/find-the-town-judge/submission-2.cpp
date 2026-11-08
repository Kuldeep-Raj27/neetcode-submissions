class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < trust.size(); i++) {
            m[trust[i][1]].push_back(trust[i][0]);
        }
     
bool ans=false;
int keyA=-1;
for (const auto& [key, values] : m) {
    if (values.size() == n - 1) {
        ans=true;
keyA = key;
    }
}
if(ans){
    for(auto i:trust){
        if(i[0]==keyA){
            return -1;
        }
    }
    return keyA;
}

return -1;
    }
};