class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for (auto x: nums2){
            if (st.empty() || (st.top()>x)) st.push(x);
            else{
                while (!st.empty() && st.top() < x){
                    mp[st.top()] = x;
                    st.pop();
                }
                st.push(x);
            }
        }
        while (!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> res;
        for (auto x: nums1){
            res.push_back(mp[x]);
        }
        return res;

    }
};