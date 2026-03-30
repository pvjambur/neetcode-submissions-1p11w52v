class Solution {
public:
    vector<string> res;
    void backTrack(int open, int close, int n, string& cur){
        if (open>n || close>n) return;
        if (open==n && close==n){
            res.push_back(cur);
            return;
        }

        
        if (open<n){ 
            cur+='(';
            backTrack(open+1,close,n,cur);
            cur.pop_back();
        }
        if (open>close){
            cur+=')';
            backTrack(open,close+1,n,cur);
            cur.pop_back();
        }
        
        
    }

    vector<string> generateParenthesis(int n) {
        string cur="";
        backTrack(0,0,n,cur);
        return res;
    }
};
