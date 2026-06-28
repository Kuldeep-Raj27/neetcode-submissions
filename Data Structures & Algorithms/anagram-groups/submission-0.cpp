class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> s_map;
        for(auto str : strs){
            string s = str;
            sort(s.begin(),s.end());
            if (s_map.contains(s)){
                ans[s_map[s]].push_back(str);
            }
            else{
            ans.push_back({str});
            int i = ans.size() - 1;
            s_map[s] =   i;    }
        
        
        }
        return ans;
    }
};
