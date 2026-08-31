class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_hashset;
        for(const auto& i:nums){
            nums_hashset.insert(i);
        }
        int ans=0;
        for(const auto& i:nums){
            if(nums_hashset.find(i-1) == nums_hashset.end()){
                int curr = i;
                int this_loop=1;
                while(true){
                    curr++;
                    if(nums_hashset.find(curr) != nums_hashset.end()){
                        this_loop++;
                    }
                    else{
                        break;
                    }
                }
                if(this_loop>ans){
                    ans = this_loop;
                }
            }
        }
        return ans;
    }
};
