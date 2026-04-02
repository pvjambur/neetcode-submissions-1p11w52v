class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        for (char c : s) {
            if (c == '1') ones++;
        }

        int zeros = s.size() - ones;

        string res = "";

        // front: max 1s
        res += string(ones - 1, '1');

        // middle: all 0s
        res += string(zeros, '0');

        // last: must be 1 (to make odd)
        res += '1';

        return res;
    }
};