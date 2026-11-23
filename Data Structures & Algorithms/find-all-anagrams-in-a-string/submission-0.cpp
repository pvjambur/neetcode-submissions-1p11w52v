class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        sort(p.begin(), p.end());

        for (int i = 0; i <= n - m; i++) {
            string sub = s.substr(i, m);
            sort(sub.begin(), sub.end());
            if (sub == p) {
                res.push_back(i);
            }
        }
        return res;
    }
};