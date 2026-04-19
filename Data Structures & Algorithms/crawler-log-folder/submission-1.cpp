class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for (auto x: logs){
            if (!st.empty() && x[0]=='.' && x[1]=='.') st.pop();
            else if (x[0]=='.' && x[1]=='/') continue;
            else st.push(1);
        }
        int count=0;
        while (!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};