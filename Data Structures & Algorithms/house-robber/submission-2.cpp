class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int house1 = 0;
        int house2 = 0;

        for(int i=0; i<n; i++){
            int res = max(house1 + nums[i], house2);
            house1 = house2;
            house2 = res;
        }
        return house2;
    }
};
