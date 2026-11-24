class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c: s){
            if ((int)(c-'0')>=0 && (int)(c-'0')<=9){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string res = "";
        while (!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
