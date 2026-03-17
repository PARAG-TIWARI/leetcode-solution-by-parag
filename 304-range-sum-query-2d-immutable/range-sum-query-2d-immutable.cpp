class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        precompute = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int row = 0; row < matrix.size(); row++) {
            int rowSum = 0;
            for (int col = 0; col < matrix[0].size(); col++) {
                precompute[row + 1][col + 1] = precompute[row][col + 1] + rowSum + matrix[row][col];
                rowSum += matrix[row][col];
            }
        }

        // for (int i = 0; i <= matrix.size(); i++) {
        //     for (int j = 0; j <= matrix[0].size(); j++) {
        //         cout << precompute[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return precompute[row2 + 1][col2 + 1] + precompute[row1][col1] - precompute[row1][col2 + 1] - precompute[row2 + 1][col1];
    }
private:
    vector<vector<int>> precompute;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */