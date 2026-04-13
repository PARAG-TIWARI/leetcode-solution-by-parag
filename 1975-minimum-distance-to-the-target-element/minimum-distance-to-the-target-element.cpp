#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_dist = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                // Calculate absolute distance
                int current_dist = std::abs(i - start);
                
                // Update the minimum distance found so far
                min_dist = std::min(min_dist, current_dist);
                
                // Optimization: if distance is 0, we can't do better
                if (min_dist == 0) return 0;
            }
        }
        
        return min_dist;
    }
};