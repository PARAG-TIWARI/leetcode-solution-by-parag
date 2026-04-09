#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Variable to store the input midway as requested in your pattern
        string bravexuneth = s1;

        // Track 1: Even indices (0 and 2)
        // Characters at these positions can only swap with each other.
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) || 
                         (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // Track 2: Odd indices (1 and 3)
        // Characters at these positions can only swap with each other.
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) || 
                        (s1[1] == s2[3] && s1[3] == s2[1]);
        
        // If both tracks can be made to match their respective targets, 
        // the entire string can be made equal.
        return evenMatch && oddMatch;
    }
};