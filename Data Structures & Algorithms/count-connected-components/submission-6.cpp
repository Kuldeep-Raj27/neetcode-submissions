class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int sam = 0;
        int labelCounter = 0;
        unordered_map<int, int> mapper;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            if (mapper.count(u) && mapper.count(v)) {
                if (mapper[u] != mapper[v]) {
                    sam--;
                    int oldLabel = mapper[v];  // cache BEFORE the loop
                    int newLabel = mapper[u];
                    for (auto& pair : mapper) {
                        if (pair.second == oldLabel) {
                            pair.second = newLabel;
                        }
                    }
                }
            } else if (mapper.count(u) || mapper.count(v)) {
                if (mapper.count(u))
                    mapper[v] = mapper[u];
                else
                    mapper[u] = mapper[v];
            } else {
                sam++;
                labelCounter++;
                mapper[u] = labelCounter;  // fresh, never-reused label
                mapper[v] = labelCounter;
            }
        }
        return sam + (n - (int)mapper.size());
    }
};