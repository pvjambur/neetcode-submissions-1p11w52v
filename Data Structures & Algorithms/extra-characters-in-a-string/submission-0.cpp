class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();

        unordered_set<string> st(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, 0);

        // dp[i] = minimum extra chars from i -> end

        for (int i = n - 1; i >= 0; i--) {

            // take current char as extra
            dp[i] = 1 + dp[i + 1];

            string temp = "";

            for (int j = i; j < n; j++) {

                temp += s[j];

                // if substring exists in dictionary
                if (st.count(temp)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};