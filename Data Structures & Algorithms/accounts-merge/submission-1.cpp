class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> owner;

    string find(string x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string a, string b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // Initialize DSU
        for (auto &acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                parent.emplace(acc[i], acc[i]);
                owner[acc[i]] = acc[0];
            }
        }

        // Union emails in same account
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                unite(acc[1], acc[i]);
            }
        }

        // Group emails
        unordered_map<string, vector<string>> groups;

        for (auto &p : parent) {
            string email = p.first;
            groups[find(email)].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto &g : groups) {
            sort(g.second.begin(), g.second.end());

            vector<string> cur;
            cur.push_back(owner[g.first]);

            for (auto &mail : g.second)
                cur.push_back(mail);

            ans.push_back(cur);
        }

        return ans;
    }
};