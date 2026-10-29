class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool ender = false;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int> inter = intervals[i];

            if ((ender) || (inter[1] < newInterval[0])) {
                ans.push_back(inter);
            }
            else if (inter[0] > newInterval[1]){
                ender = true;
                ans.push_back(newInterval);
                ans.push_back(inter);
            }
            // overlap handling
            else {
                ender= true;
                int start = (inter[0] < newInterval[0]) ? inter[0] : newInterval[0];
                int end;
                if (inter[1] >= newInterval[1]) {
                    end = inter[1];
                } 
                else{
                    int j = i;
                    end = newInterval[1];

                    while(j < intervals.size() - 1){
                    j++;
                    if ((intervals[j][0]) > newInterval[1]) {
                        end = newInterval[1];
                        j--;
                        break;       
                    } else if(intervals[j][1]>=newInterval[1]){
                        end = intervals[j][1];
                        break;                        
                    }
                    }
                    i = j;
                }

                ans.push_back({start, end});
            }
        }
        if(!ender){
            ans.push_back(newInterval);
        }

        return ans;
    }
};
