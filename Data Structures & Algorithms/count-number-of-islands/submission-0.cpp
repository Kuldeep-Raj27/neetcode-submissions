class Solution {
public:

    void huntai(vector<vector<char>>& grid,int i, int j, int l, int b){
        if((j+1)<b){
            if(grid[i][j+1]=='1'){
                grid[i][j+1] = '0';
                huntai(grid, i, j+1,l,b);
            }
        }
        if((j-1)>=0){
            if(grid[i][j-1]=='1'){
                grid[i][j-1] = '0';
                huntai(grid, i, j-1,l,b);
            }
        }
        if((i+1)<l){
            if(grid[i+1][j]=='1'){
                grid[i+1][j] ='0';
                huntai(grid,i+1,j,l,b);
            }
        }
         if((i-1)>=0){
            if(grid[i-1][j]=='1'){
                grid[i-1][j] ='0';
                huntai(grid,i-1,j,l,b);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int l = grid.size();
        if(l==0){
            return 0;
        }
        int b = grid[0].size();
        int count=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<b;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    count++;
                    huntai(grid,i,j,l,b);
                }
            }
        }
        return count;
    }
};
