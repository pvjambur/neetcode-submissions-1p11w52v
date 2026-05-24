class Solution {
private:
    vector<string> neigs(string s){
        vector<string> res;
        for (int i=0;i<4;i++){
            string u = s,d = s;
            u[i] = (s[i]=='9') ? '0' : char(s[i]+1);
            d[i] = (s[i]=='0') ? '9' : char(s[i]-1);
            res.push_back(u);
            res.push_back(d);
        }
        return res;
    }


public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        int moves = 0;
        queue<string> q;
        if (ends.count("0000")) return -1;
        q.push("0000");

        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                string cur = q.front();
                q.pop();

                if (cur==target) return moves;

                for (string s: neigs(cur)){
                    if (!ends.count(s) && !vis.count(s)){
                        q.push(s);
                        vis.insert(s);
                    }
                }
            }
            moves++;
        }
        return -1;
        
    }
};