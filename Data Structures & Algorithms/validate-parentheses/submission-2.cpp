class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.size();i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if (st.empty()) return false;
            else if (s[i]==')' || s[i]=='}' || s[i]==']'){
                char temp = st.top();
                if (temp=='(' && s[i]==')') st.pop();
                else if (temp=='{' && s[i]=='}') st.pop();
                else if (temp=='[' && s[i]==']') st.pop();
                else return false;
            }
            else return false;
        }
        if (st.empty()) return true;
        return false;
    }
};
