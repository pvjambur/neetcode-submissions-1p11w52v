class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i=0;i<asteroids.size();i++){
            int cur = asteroids[i];
            if (st.empty()) st.push(cur);
            else{
                if (asteroids[i]>0) st.push(cur);
                else{
                    while (!st.empty()){
                        int temp = st.top();
                        if (abs(cur)>temp) st.pop();
                        else if (temp>abs(cur)) break;
                        else{
                            cur=0;
                            st.pop();
                            break;
                        }
                    }
                    if (st.empty() && abs(cur)!=0) st.push(cur);
                }
            }
        }
        vector<int> res;
        while (!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};