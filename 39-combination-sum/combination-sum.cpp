#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& currentPath) {
        // Base Case: If the target is met
        if (target == 0) {
            result.push_back(currentPath);
            return;
        }

        // Base Case: If we've run out of candidates or target becomes negative
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Choice 1: Include the current candidate
        // We stay at the same index because we can reuse the number
        if (candidates[index] <= target) {
            currentPath.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, result, currentPath);
            
            // Backtrack: remove the last element before trying the next choice
            currentPath.pop_back();
        }

        // Choice 2: Skip the current candidate and move to the next one
        findCombinations(index + 1, target, candidates, result, currentPath);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentPath;
        findCombinations(0, target, candidates, result, currentPath);
        return result;
    }
};