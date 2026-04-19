class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        int count = 0;
        int comp = 0;
        for (auto x: s){
            if (x=='*') comp++;
            else if (x=='(') st.push(x);
            else{
                if (st.empty()){
                    if (comp>0) comp--;
                    else count++;
                }
                else st.pop();
            }
        }
        while (!st.empty()){
            st.pop();
            if (comp>0) comp--;
            else count++;
        }

        if (count>0) return false;
        return true;
    }
};
