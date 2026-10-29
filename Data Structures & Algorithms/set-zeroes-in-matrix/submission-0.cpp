class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        set<int> rows_to_fuck;
        set<int> cols_to_fuck;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    rows_to_fuck.insert(i);
                    cols_to_fuck.insert(j);
                }
            }
        }

        for(int row: rows_to_fuck){
            for(int j=0;j<cols;j++){
                matrix[row][j]=0;
            }
        }
         for(int col: cols_to_fuck){
            for(int j=0;j<rows;j++){
                matrix[j][col]=0;
            }
        }
    }
};
