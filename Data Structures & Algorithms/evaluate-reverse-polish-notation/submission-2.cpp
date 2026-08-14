class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> ops = {"+","-","*","/"};
        for (auto &s: tokens){
            if (ops.count(s)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (s=="+"){
                    st.push(a+b);
                }
                else if (s=="-"){
                    st.push(a-b);
                }
                else if (s=="*"){
                    st.push(a*b);
                }
                else if (s=="/"){
                    st.push(a/b);
                }
                else{
                    return -1;
                }
            }
            else{
                st.push(stoi(s));
            }
        }

        if (st.size()>=2) return -1;
        return st.top();
    }
};
