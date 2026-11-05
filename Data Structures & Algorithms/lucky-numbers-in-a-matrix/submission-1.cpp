class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int x=0,y=0;
        int lenX= matrix.size();
        int lenY = matrix[0].size();
        for(int i=0;i<lenX;i++){
            int smallestX = matrix[i][0];
             for(int j=0;j<lenY;j++){
                if(matrix[i][j]<=smallestX){
                    smallestX = matrix[i][j];
                    x=i;
                    y=j;
                }

            }
            bool nope= true;
            for(int k=0;k<lenX;k++){
                if(smallestX<matrix[k][y]){
                    nope = false;
                }
            }
            if(nope){
                ans.push_back(smallestX);
            }
           
        }
return ans;
    }
};
