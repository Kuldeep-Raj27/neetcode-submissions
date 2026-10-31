class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // to remember - 
        vector<vector<bool>> inRow(9,vector<bool>(9,false));
        vector<vector<bool>> inCol(9,vector<bool>(9,false));

        // need to maintain a current box grid. and also to traverse it box wise.
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            
            vector<bool> seen(10, false); 
            // Loop through the cells inside the current 3x3 sub-box
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    int currRow = boxRow + r;
                    int currCol = boxCol + c;
                    char yup = board[currRow][currCol];
                    if(yup=='.'){
                        continue;
                    }
                    else{
                        yup = yup - '0';
                    }
                    
                    if(seen[yup] || inRow[yup-1][currRow] || inCol[yup-1][currCol]){
                        return false;
                    }
                    else{
                        seen[yup] = true;
                        inRow[yup-1][currRow] = true;
                        inCol[yup-1][currCol] = true;
                    }
                    
                    
                }
            }

        }
    }
    return true;

        
    }
};
