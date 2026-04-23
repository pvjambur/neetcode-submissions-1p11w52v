class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> g;
        unordered_map<char, int> indeg;

        for (auto &w : words) {
            for (char c : w) indeg[c] = 0;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i], b = words[i + 1];
            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    g[a[j]].push_back(b[j]);
                    indeg[b[j]]++;
                    found = true;
                    break;
                }
            }

            if (!found && a.size() > b.size()) return "";
        }

        queue<char> q;
        for (auto &x : indeg) {
            if (x.second == 0) q.push(x.first);
        }

        string ans = "";

        while (!q.empty()) {
            char u = q.front(); q.pop();
            ans += u;

            for (char v : g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        if (ans.size() != indeg.size()) return "";

        return ans;
    }
};