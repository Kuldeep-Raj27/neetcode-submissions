class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int end_r, end_c;
        (m <= n) ? (m % 2 ? (end_r = m / 2, end_c = n - 1 - m / 2) : (end_r = m / 2, end_c = m / 2 - 1))
         : (n % 2 ? (end_r = m - 1 - n / 2, end_c = n / 2) : (end_r = n / 2, end_c = n / 2 - 1));


        vector<int> ans;
        int r=0,c=0;
        int i=0,j=0;

unordered_map<int,vector<int>> flow;
flow[1] = {0,1};
flow[2] = {1,0};
flow[3] = {0,-1};
flow[4] = {-1,0};
int mode = 1;     

        while((i<m && j<n)){
           while((i<=r && r<m) && (j<=c && c<n)){
                ans.push_back(matrix[r][c]);
                r += flow[mode][0];
                c += flow[mode][1];
            }

            r -= flow[mode][0];
            c -= flow[mode][1];
            if(r==end_r && c==end_c){
                break;
            }
            // Change mode & fix limits
            switch(mode){
              case 1:
                    i++;
                    break;
              case 2:
                    n--;
                    break;
               case 3:
                    m--;
                    break;  
               case 4:
                    j++;
                    break;         
            }

            mode = (mode%4)+1;
            r += flow[mode][0];
            c += flow[mode][1];

          
        }
        return ans;        
    }
};
