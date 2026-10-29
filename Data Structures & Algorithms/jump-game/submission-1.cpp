class Solution {
   public:
    bool canJump(vector<int>& nums) {
        // 2, 5 ,0 ,0
        // i know - total steps - size of num. it is 4.
        // _2_ __ __ __
        // i went to i=1. see 5
        // TotalPower - 2 --1 or 5. 5 -> win.

        // TotalPower = 1, --0, 2, --1, --0, 1 --0 but win.
        // TP = 1, --0 2, --1, 0 end.

        int totalPower = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totalPower--;
            if (totalPower < nums[i]) {
                totalPower = nums[i];
            }

            if (totalPower >= (n - i - 1)) return true;
            if (totalPower == 0 && i != n - 1) return false;
        }
        return true;
    }
};
