class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        if (ransomNote.size()>magazine.size()) return false;
        for (auto x: magazine){
            arr[x-'a']++;
        }
        for (auto x: ransomNote){
            arr[x-'a']--;
        }
        for (int i=0;i<26;i++){
            if (arr[i]<0) return false;
        }
        return true;
    }
};