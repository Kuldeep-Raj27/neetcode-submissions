class Solution {
   public:
    // Optimized - memoisation
    int def1(vector<int>& nums, int len, vector<int>& dp, int i) {
        if (i >= len) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(nums[i] + def1(nums, len, dp, i + 2), def1(nums, len, dp, i + 1));
    }

    int rob(vector<int>& nums) {
        //  return def(nums, nums.size(), 0);
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(def1(nums,nums.size(),dp1,1),def1(nums, nums.size()-1, dp2, 0));
    }
};
