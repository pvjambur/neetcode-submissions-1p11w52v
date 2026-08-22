class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> memo;
    int n;

    vector<string> solve(int i, string& s) {

        if (i == n)
            return {""};

        if (memo.count(i))
            return memo[i];

        vector<string> ans;
        string word = "";

        for (int j = i; j < n; j++) {

            word += s[j];

            if (st.count(word)) {

                vector<string> suffixes = solve(j + 1, s);

                for (string& suffix : suffixes) {

                    if (suffix == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + suffix);
                }
            }
        }

        return memo[i] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        n = s.size();

        for (string& word : wordDict)
            st.insert(word);

        return solve(0, s);
    }
};