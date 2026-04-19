class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int n = s.size();
        for (int i=0;i<n;i++){
            if (mp.find(s[i])!=mp.end()){
                if (mp[s[i]]!=t[i]) return false;
            }
            else{
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
};