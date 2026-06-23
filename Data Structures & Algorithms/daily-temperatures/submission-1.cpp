class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n,0);
        for (int i=n-1;i>=0;i--){
            if (st.empty()){
                res[i] = 0;
                st.push(i);
            }
            else{
                int count = 0;
                while (!st.empty() && temperatures[i]>=temperatures[st.top()]){
                    st.pop();
                }
                if (st.empty()){
                    res[i] = 0;
                    st.push(i);
                }
                else{
                    res[i] = abs(st.top() - i);
                    st.push(i);
                }

            }
        }
        return res;
    }
};
