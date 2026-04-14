#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Base case: if either number is "0", the product is "0"
        if (num1 == "0" || num2 == "0") return "0";

        // The product of a length N and length M number can be at most N+M digits
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);

        // Multiply each digit and add to the corresponding position in the vector
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;   // Units place of the current product
                res[i + j] += sum / 10;       // Carry to the next position
            }
        }

        // Convert the vector of digits back into a string
        string result = "";
        for (int digit : res) {
            // Skip leading zeros
            if (!(result.empty() && digit == 0)) {
                result += to_string(digit);
            }
        }

        return result.empty() ? "0" : result;
    }
};