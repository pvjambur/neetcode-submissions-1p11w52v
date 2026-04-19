class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr1[26];
        int arr2[26];
        fill(arr1, arr1 + 26, -1);
        fill(arr2, arr2 + 26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (arr1[s[i]-'a'] == -1 && arr2[t[i]-'a'] == -1) {
                arr1[s[i]-'a'] = t[i]-'a';
                arr2[t[i]-'a'] = s[i]-'a';
            }
            else if (arr1[s[i]-'a'] != -1 && arr2[t[i]-'a'] != -1) {
                if (arr1[s[i]-'a'] != t[i]-'a' ||
                    arr2[t[i]-'a'] != s[i]-'a') {
                    return false;
                }
            }
            else return false;
        }
        return true;
    }
};