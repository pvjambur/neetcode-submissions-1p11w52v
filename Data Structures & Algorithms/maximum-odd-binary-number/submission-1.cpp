class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        for (char c : s) {
            if (c == '1') ones++;
        }

        int zeros = s.size() - ones;

        string res = "";


        res += string(ones - 1, '1');

        
        res += string(zeros, '0');


        res += '1';

        return res;
    }
};