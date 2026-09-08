class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> res;

        for (string& word : words) {
            st.erase(word);

            int n = word.size();

            vector<bool> dp(n + 1, false);
            dp[0] = true;

            for (int i = 0; i < n; i++) {
                if (!dp[i])
                    continue;

                string cur = "";

                for (int j = i; j < n; j++) {
                    cur += word[j];

                    if (st.count(cur)) {
                        dp[j + 1] = true;
                    }
                }
            }

            if (dp[n])
                res.push_back(word);

            st.insert(word);
        }

        return res;
    }
};