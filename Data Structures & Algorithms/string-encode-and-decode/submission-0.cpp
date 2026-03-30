class Solution {
public:

    string encode(vector<string>& strs) {
        string enc="";
        for (auto &s: strs){
            int n = s.size();
            enc += to_string(n) + "#";
            enc += s;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while (i<s.size()){
            int j=i;
            while (s[j]!='#') j++;
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;

        }
        return res;
    }
};
