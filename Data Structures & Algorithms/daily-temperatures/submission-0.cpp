class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for (int i=0;i<n;i++){
            while (!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prevind = st.top();
                st.pop();
                res[prevind] = i - prevind;
            }
            st.push(i);
        }
        return res;
    }
};
