class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for (int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int top = heights[st.top()];
                st.pop();
                int width=0;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;

                maxArea = max(maxArea,top*width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int top = heights[st.top()];
            st.pop();
            int width;
            if (st.empty()) width = n;
            else width = n - st.top() - 1;

            maxArea = max(maxArea, top * width);
        }

        return maxArea;

    }
};
