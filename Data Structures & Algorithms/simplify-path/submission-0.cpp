class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        st.push("/");
        int n = path.size();
        for (int i=0;i<n;i++){
            if (path[i]!='/'){
                temp+=path[i];
            }
            if (path[i]=='/' || i==n-1) {
                if (temp=="") continue;
                else if (temp=="."){
                    temp="";
                }
                else if (temp==".."){
                    if (st.size()==1){
                        temp="";
                        continue;
                    }
                    st.pop();
                    st.pop();
                    temp="";
                }
                else{
                    st.push(temp);
                    st.push("/");
                    temp="";
                }
            }
        }

        if (st.size()==1) return "/";
        st.pop();
        string res = "";
        while (!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
        
    }
};