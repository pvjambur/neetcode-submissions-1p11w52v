class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        int i=0,j=0;
        int n1 = pattern.size(),n2 = s.size();
        while (i<n1){
            string temp = "";
            while (j<n2 && s[j]!=' ') temp+=s[j++];
            j++;
            if (mp.find(pattern[i])!=mp.end()){
                if (mp[pattern[i]]!=temp) return false;
            }
            else{
                mp[pattern[i]] = temp;
            }
            i++;
        }
        return true;
    }
};