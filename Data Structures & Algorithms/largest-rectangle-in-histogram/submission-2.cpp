class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int h = heights[st.top()];
            st.pop();
            int left = -1;
            if (!st.empty()) left = st.top();
            int width = i-left-1;
            ans = max(ans,h*width);
        }
        st.push(i);

        }
    while (!st.empty()){
        int h = heights[st.top()];
        st.pop();
        int left = -1;
        if (!st.empty()){
            left = st.top();
        }
        int width =n-left-1;
        ans = max(ans,h*width);
    }
    return ans;
    
    }
};
