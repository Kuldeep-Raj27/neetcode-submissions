class Solution {
   public:
//  using simple recusrion.. (TLE)
    int def(vector<int>& nums, int len, int i) {
        if (i >= len) {
            return 0;
        }
        return max(nums[i] + def(nums, len, i + 2), def(nums, len, i + 1));
    }

// Optimized - memoisation
    int def1(vector<int>& nums, int len,vector<int>& dp, int i) {
        if (i >= len) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        return dp[i] = max(nums[i] + def1(nums, len,dp, i + 2), def1(nums, len, dp,i + 1));
    }

    int rob(vector<int>& nums) 
    {
        //  return def(nums, nums.size(), 0); 
        vector<int> dp(nums.size(),-1);
        return def1(nums, nums.size(),dp,0);
    }
};
