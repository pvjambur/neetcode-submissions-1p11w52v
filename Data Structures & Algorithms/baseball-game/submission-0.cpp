class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto x: operations){
            if (x[0]=='+' && st.size()>=2){
                int s1 = st.top();
                st.pop();
                int s2 = st.top();
                st.push(s1);
                st.push(s1+s2);
            }
            else if (x[0]=='D' && !st.empty()){
                int s1 = st.top();
                st.push(2*s1);
            }
            else if (x[0]=='C' && !st.empty()){
                st.pop();
            }
            else{
                int s1 = stoi(x);
                st.push(s1);
            }
        }
        int score = 0;
        while (!st.empty()){
            score += st.top();
            st.pop();
        }
        return score;
    }
};