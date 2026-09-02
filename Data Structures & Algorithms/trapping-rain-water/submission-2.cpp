class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        int water = 0;
        for (int i=0;i<n;i++){
            while (!st.empty() && height[i]>=height[st.top()]){
                int mid = height[st.top()];
                st.pop();

                if (st.empty()) break;
                int left = st.top();
                int h = min(height[left],height[i]) - mid;
                int width = i - left -1;
                water += h*width;
            }
            st.push(i);
        }
        return water;
    }
};
