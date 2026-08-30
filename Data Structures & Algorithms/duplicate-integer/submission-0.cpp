class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        if( mySet.size() == nums.size()){
            return false; 
            }
        else{
            return true;
        } 
        
    }
};