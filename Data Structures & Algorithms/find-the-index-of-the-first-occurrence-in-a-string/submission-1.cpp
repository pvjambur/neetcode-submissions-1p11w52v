class Solution {
public:
    int strStr(string haystack, string needle) {

        int n1 = haystack.size();
        int n2 = needle.size();

        for (int i = 0; i <= n1 - n2; i++) {

            int j = i;
            int k = 0;

            while (k < n2 && haystack[j] == needle[k]) {
                j++;
                k++;
            }

            if (k == n2) return i;
        }

        return -1;
    }
};