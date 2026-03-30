class Solution {
public:
    vector<string> res;
    unordered_map<char,string> mp;

    void backTrack(int ind, string& digits, string& cur){
        if (cur.size()==digits.size()){
            res.push_back(cur);
            return;
        }
        string temp = mp[digits[ind]];
        for (int i=0;i<temp.size();i++){
            cur += temp[i];
            backTrack(ind+1,digits,cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if (n==0) return res;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string cur = "";
        backTrack(0,digits,cur);
        return res;
    }
};
