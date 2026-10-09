class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0;
        for(auto i:nums){
            sum += i;
        }
        int len = nums.size();
        int needed = (len)*(len+1)/2;
        cout<<len<<" :"<<sum<<":"<<needed<<endl;
        return needed - sum; 
        
    }
};
