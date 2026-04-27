class Solution {
public:
    int dp[21][21];

    bool solve(int i, int j, string &s, string &p) {
        if (j == p.size()) return i == s.size();

        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Case 1: skip x*
            // Case 2: use x* if match
            ans = solve(i, j + 2, s, p) || (match && solve(i + 1, j, s, p));
        } else {
            ans = match && solve(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};