class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count frequencies using a hash map
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        // Step 2: Create buckets where the index represents the frequency
        // We need n + 1 buckets (indices 0 to n)
        std::vector<std::vector<int>> buckets(n + 1);
        for (auto& p : counts) {
            int element = p.first;
            int frequency = p.second;
            buckets[frequency].push_back(element);
        }
        
        // Step 3: Gather the top k elements from right to left
        std::vector<int> result;
        for (int i = n; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                // Stop once we have gathered k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};