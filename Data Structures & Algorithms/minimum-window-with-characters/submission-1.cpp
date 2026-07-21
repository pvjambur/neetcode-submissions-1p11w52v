class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        string wind="";
        for (int i=0;i<t.size();i++){
            if (mp.find(t[i])!=mp.end()) mp[t[i]]++;
            else mp[t[i]]=1;
        }
        unordered_map<char,int> mp_dup = mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {

                unordered_map<char,int> mp_dup = mp;
                string temp_wind = "";

                for (int j = i; j < n; j++) {

                    temp_wind += s[j];

                    if (mp_dup.find(s[j]) != mp_dup.end()) {
                        mp_dup[s[j]]--;
                        if (mp_dup[s[j]] == 0)
                            mp_dup.erase(s[j]);
                    }

                    if (mp_dup.empty()) {
                        if (wind == "" || temp_wind.size() < wind.size())
                            wind = temp_wind;
                        break;
                    }
                }
            }
        }
        return wind;

    }
};
