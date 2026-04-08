class Solution {
private:
    bool isPrefixAndSuffix(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2) return false;

        return (s2.substr(0, n1) == s1) &&
               (s2.substr(n2 - n1, n1) == s1);
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};