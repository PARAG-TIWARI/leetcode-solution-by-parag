class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;

        // Count frequency
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Bucket sort
        vector<vector<int>> bucket(n + 1);

        for(auto x : mp) {
            int element = x.first;
            int freq = x.second;
            bucket[freq].push_back(element);
        }

        vector<int> ans;

        // Traverse from highest frequency
        for(int i = n; i >= 0 && ans.size() < k; i--) {
            if(!bucket[i].empty()) {
                for(int j = 0; j < bucket[i].size(); j++) {
                    ans.push_back(bucket[i][j]);
                    if(ans.size() == k) return ans;
                }
            }
        }

        return ans;
    }
};