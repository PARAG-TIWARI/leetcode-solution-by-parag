class Solution {
public:
    bool isPalindrome(int x) {
        // negative or ends with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;

        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        // for even digits: x == rev
        // for odd digits: x == rev/10
        return (x == rev || x == rev / 10);
    }
};