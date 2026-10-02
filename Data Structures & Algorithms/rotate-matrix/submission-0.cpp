class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
            //    A -> reverse vector -> Transpose it. to rotate
            reverse(matrix.begin(), matrix.end()); 

            int n = matrix.size();
            for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    }
};
