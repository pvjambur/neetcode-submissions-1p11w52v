class Solution {
public:
    vector<vector<string>> res;
    bool isPali(string& s, int l, int r){
        while (l<r){
            if (s[l++]!=s[r--]) return false;
        }
        return true;
    }

    void backtrack(int start, string& s, vector<string>& path){
        if (start==s.size()){
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++){
            if (isPali(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                backtrack(end+1,s,path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0,s,path);
        return res;
    }
};
