class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr1[256];
        int arr2[256];
        fill(arr1, arr1 + 256, -1);
        fill(arr2, arr2 + 256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (arr1[s[i]] == -1 && arr2[t[i]] == -1) {
                arr1[s[i]] = t[i];
                arr2[t[i]] = s[i];
            }
            else if (arr1[s[i]] != t[i] || arr2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};