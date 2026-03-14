class Solution {
public:
    vector<string> res;

    void backtrack(string s, int n) {
        if (res.size() >= 100) return;  // optional early stop

        if (s.length() == n) {
            res.push_back(s);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch) {
                backtrack(s + ch, n);
            }
        }
    }

    string getHappyString(int n, int k) {
        backtrack("", n);

        if (k > res.size()) return "";
        return res[k - 1];
    }
};
