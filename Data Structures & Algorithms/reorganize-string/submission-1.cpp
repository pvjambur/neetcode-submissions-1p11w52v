class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int n = s.size();
        int trs = ceil((double)n/2) + 1;
        vector<int> alpha(26,0);
        for (char c: s){
            alpha[c-'a']++;
            if (alpha[c-'a']==trs) return res;
        }

        priority_queue<pair<int,char>> pq;

        for (int i=0;i<26;i++){
            if (alpha[i]!=0){
                pq.push({alpha[i],char('a'+i)});
            }
        }

        while (n!=0){
            int k = res.size();
            if (k==0 && !pq.empty()){
                auto [m,c] = pq.top();
                pq.pop();
                res+=c;
                pq.push({m-1,c});
                n--;
            }
            else if (k>=1 && !pq.empty()){
                auto [m,c] = pq.top();
                pq.pop();
                if (res[k-1]==c && !pq.empty()){
                    auto [m1,c1] = pq.top();
                    pq.pop();
                    res+=c1;
                    pq.push({m1-1,c1});
                }
                else{
                    res+=c;
                    m = m-1;
                }
                pq.push({m,c});
                n--;
            }
        }

        return res;

    }
};