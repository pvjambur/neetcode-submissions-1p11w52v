class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int n1 = word.size(), n2 = abbr.size();

        while (i < n1 && j < n2) {
            if (isdigit(abbr[j])) {
                // leading zero is invalid
                if (abbr[j] == '0') return false;

                int num = 0;
                while (j < n2 && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num; // skip characters in word
            } 
            else {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }

        return i == n1 && j == n2;
    }
};