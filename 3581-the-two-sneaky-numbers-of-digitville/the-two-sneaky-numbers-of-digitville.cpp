class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2, x = 0;

        for (int v : nums) x ^= v;
        for (int i = 0; i < n; i++) x ^= i;

        int bit = x & -x, a = 0, b = 0;

        for (int v : nums)
            (v & bit) ? a ^= v : b ^= v;

        for (int i = 0; i < n; i++)
            (i & bit) ? a ^= i : b ^= i;

        return {a, b};
    }
};