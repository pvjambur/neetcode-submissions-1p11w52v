class Solution {
private:
    bool isAnag(string s1, string s2){
        int changes=0;
        for (int i=0;i<s1.size();i++){
            if (s1[i]!=s2[i]) changes++;
            if (changes>=2) return false;
        }
        if (changes==1) return true;
        return false;
    }

    vector<string> neigs(string s, unordered_set<string>& st, unordered_set<string>& vis){
        vector<string> res;
        for (auto &p: st){
            if (isAnag(s,p) && !vis.count(p)){
                res.push_back(p);
            }
        }
        return res;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_set<string> vis;
        if (beginWord==endWord) return 0;
        int words=1;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                string cur = q.front();
                q.pop();
                if (cur==endWord) return words;

                for (string temp: neigs(cur,st,vis)){
                    q.push(temp);
                    vis.insert(temp);
                }
            }
            words++;
        }
        return 0;
    }

};
