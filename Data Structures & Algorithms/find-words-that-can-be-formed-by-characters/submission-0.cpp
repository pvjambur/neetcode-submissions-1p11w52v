class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> alpha(26,0);
        for (char c: chars){
            alpha[c-'a']++;
        }
        int sz = 0;
        for (auto &s: words){
            bool flag = true;
            vector<int> temp(26,0);
            for (char c: s){
                temp[c-'a']++;
            }

            for (int i=0;i<26;i++){
                if (temp[i]>alpha[i]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                sz += s.size();
            }
        }
        return sz;
    }
};