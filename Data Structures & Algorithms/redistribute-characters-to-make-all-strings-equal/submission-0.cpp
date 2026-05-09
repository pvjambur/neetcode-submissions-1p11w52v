class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> alpha(26,0);
        for (auto &s: words){
            for (char c: s){
                alpha[c-'a']++;
            }
        }

        int n = words.size();

        for (int i=0;i<26;i++){
            if (alpha[i]%n!=0) return false;
        }
        return true;
    }
};