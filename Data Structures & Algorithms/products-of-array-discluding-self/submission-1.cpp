class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multi =1;
        bool Bura = false;
        for(auto i: nums){
            if(Bura==true || i!=0){
            multi *= i;
            }
            else{
                Bura = true;
            }
        }
        vector<int> output(nums.size());
        for(int i=0;i<nums.size();i++){
            if(Bura==true && nums[i]!=0){
                output[i] = 0;
            }
            else if(nums[i]!=0){
            output[i] = multi/nums[i];
            }
            else{
                output[i] = multi;
            }
        }
        return output;
 
    }
};
