class MinStack {
public:
    stack<int> st,min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (min_st.empty()) min_st.push(val);
        else min_st.push(min(min_st.top(),val));
    }
    
    void pop() {
        if (min_st.empty()) return;
        min_st.pop();
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
