class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        
        // count total ones
        for (char c : s) {
            if (c == '1') ones++;
        }

        int leftZeros = 0;
        int ans = 0;

        // split before last character
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') leftZeros++;
            else ones--;

            ans = max(ans, leftZeros + ones);
        }

        return ans;
    }
};