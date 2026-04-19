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
                if (st.empty()) count++;
                else st.pop();
            }
        }
        while (!st.empty()){
            st.pop();
            count++;
        }

        if (comp>=count) return true;
        return false;
    }
};
