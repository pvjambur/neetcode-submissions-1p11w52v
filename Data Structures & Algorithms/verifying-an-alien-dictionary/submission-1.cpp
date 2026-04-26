class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);

        // map each character to its rank
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); i++) {
            string &w1 = words[i - 1];
            string &w2 = words[i];

            int j = 0;
            int minLen = min(w1.size(), w2.size());

            // compare character by character
            while (j < minLen && w1[j] == w2[j]) {
                j++;
            }

            // case 1: mismatch found
            if (j < minLen) {
                if (rank[w1[j] - 'a'] > rank[w2[j] - 'a'])
                    return false;
            }
            // case 2: no mismatch → prefix case
            else {
                if (w1.size() > w2.size())
                    return false;
            }
        }

        return true;
    }
};