class Solution {
public:
    bool can(long long time, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (int t : workerTimes) {
            long long val = (2 * time) / t;

            long long k = (-1 + sqrt(1 + 4 * val)) / 2;

            total += k;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};