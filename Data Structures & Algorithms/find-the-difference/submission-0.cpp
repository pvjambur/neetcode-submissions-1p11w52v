class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        for (auto x: t){
            arr[x-'a']++;
        }
        for (auto x: s){
            arr[x-'a']--;
        }
        for (int i=0;i<26;i++){
            if (arr[i]>0){
                return char(i+'a');
            }
        }
        return 'a';
    }
};