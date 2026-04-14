class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> rev;   

        int i=0,j=0;
        int n1 = pattern.size(), n2 = s.size();

        while (i<n1){
            if (j >= n2) return false;   

            string temp = "";
            while (j<n2 && s[j] != ' ') temp += s[j++];
            j++;

            if (mp.count(pattern[i])) {
                if (mp[pattern[i]] != temp) return false;
            } else {
                if (rev.count(temp)) return false; 
                mp[pattern[i]] = temp;
                rev[temp] = pattern[i];
            }
            i++;
        }

        if (j < n2) return false;

        return true;
    }
};