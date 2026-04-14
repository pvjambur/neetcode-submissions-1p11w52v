class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string &email : emails) {
            int i = 0;
            string local = "", domain = "";

          
            while (email[i] != '@') {
                if (email[i] == '+') {
                    // skip until '@'
                    while (email[i] != '@') i++;
                    break;
                }
                if (email[i] != '.') {
                    local += email[i];
                }
                i++;
            }

            i++;

            while (i < email.size()) {
                domain += email[i++];
            }

            st.insert(local + "@" + domain);
        }

        return st.size();
    }
};