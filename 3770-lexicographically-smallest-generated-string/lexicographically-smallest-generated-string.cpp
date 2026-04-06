class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        // Step 1: Apply all T constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i+j] == '?' || word[i+j] == str2[j]) {
                        word[i+j] = str2[j];
                        fixed[i+j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining positions with 'a'
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        // Step 3: Check F constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (word.substr(i, m) == str2) {
                    bool changed = false;

                    for (int j = m-1; j >= 0; j--) {
                        if (!fixed[i+j]) {
                            word[i+j] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";
                }
            }
        }

        return word;
    }
};