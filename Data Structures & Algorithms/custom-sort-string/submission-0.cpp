class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for (char c: s){
            mp[c]++;
        }
        string res = "";
        for (char c: order){
            if (mp.count(c)){
                int temp = mp[c];
                while (temp--){
                    res += c;
                }
                mp.erase(c);
            }
        }
        for (auto &[c,n]: mp){
            int temp = mp[c];
            while (temp--){
                res += c;
            }
        }
        return res;
    }
};