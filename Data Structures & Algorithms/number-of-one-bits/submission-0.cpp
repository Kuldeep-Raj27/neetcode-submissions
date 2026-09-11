class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        int bits = bit_width(n); // totle bits e.g. 5
        for(int i=0;i<bits;i++){
            int shifted = 1<<i;
            if((shifted & n) >0){
                ans++;
            }   

        }
        return ans;

    }
};
