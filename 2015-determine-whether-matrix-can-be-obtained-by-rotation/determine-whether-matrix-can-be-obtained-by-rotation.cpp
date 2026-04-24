#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate matrix 90° clockwise
    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - i - 1] = mat[i][j];
            }
        }
        return res;
    }

    // Function to check if two matrices are equal
    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
        return a == b;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (isEqual(mat, target)) return true;
            mat = rotate(mat);
        }
        return false;
    }
};