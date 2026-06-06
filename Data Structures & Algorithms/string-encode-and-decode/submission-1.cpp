class Solution {
public:

    string s = "";

    string encode(vector<string>& strs) {
        for (string s1: strs){
            s += to_string(s1.size()) + '#' + s1;
        }

        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int i=0;
        vector<string> res;
        while (i<n){
            int num = 0;
            while (s[i]!='#'){
                num = 10*num + (s[i]-'0');
                i++;
            }
            i++;
            string temp = "";
            while (num--){
                temp+=s[i];
                i++;
            }
            res.push_back(temp);

        }
        return res;
    }
};
