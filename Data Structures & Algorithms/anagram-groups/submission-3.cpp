class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (string s: strs){
            vector<int> alpha(26,0);
            for (char c: s){
                alpha[c-'a']++;
            }

            string code = "";
            for (int i=0;i<26;i++){
                code += to_string(alpha[i]) + '#';
            }

            mp[code].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &[s,v]: mp){
            res.push_back(v);
        }
        return res;
    }
};