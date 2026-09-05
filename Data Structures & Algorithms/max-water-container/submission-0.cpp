class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int x = 0;
        int y = heights.size() -1;
        int w = y-x;
        while(x<y){
            int h = min(heights[x],heights[y]);
    
            if(h*w>ans){
                ans = h*w;
            }
            
            w--;
            if(heights[x]<=heights[y]){
                x++;
            }
            else{
                y--;
            }
        }
        return ans;
    }
};
