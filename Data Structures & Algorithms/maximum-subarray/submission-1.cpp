class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int l=0,r=0;
        int currSum =0;
        int len = nums.size();
        while(r<len && l<len){
            currSum += nums[r];
             if(currSum>maxSum){
                maxSum = currSum;
            }
            if(currSum<=0){
                currSum=0;
                l = r+1;
            }
           
            r++;
        }
        return maxSum;

    }
};
