class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> open,close;
        string res = "";
        int n = s.size();
        for (int i=0;i<n;i++){
            if (s[i]=='(') st.push(i);
            else if (s[i]==')'){
                if (st.empty()) continue;
                else{
                    close.insert(i);
                    open.insert(st.top());
                    st.pop();
                }
            }
        }
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                if (open.count(i)){
                    res+='(';
                }
                else continue;
            }
            else if (s[i]==')'){
                if (close.count(i)){
                    res+=')';
                }
                else continue;
            }
            else{
                res+=s[i];
            }

        }
        return res;
    }
};