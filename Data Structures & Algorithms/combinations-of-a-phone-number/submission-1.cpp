class Solution {
private:
    vector<string> res;
    unordered_map<int,string> mp;
    int m;
    void bt(int ind, string& digits, string& cur){
        if (ind==m){
            res.push_back(cur);
            return;
        }
        string temp = mp[(int)(digits[ind]-'0')];
        for (char c: temp){
            cur += c;
            bt(ind+1,digits,cur);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string cur = "";
        m = digits.size();
        if (m==0) return res;
        bt(0,digits,cur);
        return res;
    }
};
