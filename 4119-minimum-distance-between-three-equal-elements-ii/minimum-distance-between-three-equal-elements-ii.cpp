#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Map value -> list of indices where it appears
        unordered_map<int, vector<int>> pos_map;
        
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }
        
        long long min_dist = LLONG_MAX;
        bool found = false;
        
        for (auto const& [val, indices] : pos_map) {
            // We need at least 3 occurrences to form a tuple
            if (indices.size() >= 3) {
                found = true;
                for (int m = 0; m <= (int)indices.size() - 3; ++m) {
                    // Distance is 2 * (index_k - index_i)
                    long long current_dist = 2LL * (indices[m + 2] - indices[m]);
                    if (current_dist < min_dist) {
                        min_dist = current_dist;
                    }
                }
            }
        }
        
        return found ? (int)min_dist : -1;
    }
};