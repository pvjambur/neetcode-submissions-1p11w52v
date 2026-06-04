class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a!=0) pq.push({a,'a'});
        if (b!=0) pq.push({b,'b'});
        if (c!=0) pq.push({c,'c'});
        string res = "";
        pair<int,char> conti = {0,'.'};

        while (!pq.empty()){
            auto [n,c] = pq.top();
            pq.pop();
            if (conti.second == c){
                if (conti.first==2){
                    if (pq.empty()) break;
                    else{
                        auto [n1,c1] = pq.top();
                        pq.pop();
                        conti.first = 1;
                        conti.second = c1;
                        res+=c1;
                        n1--;
                        if (n1!=0) pq.push({n1,c1});
                        
                    }
                    pq.push({n,c});
                    continue;
                }
                else conti.first++;
            }
            else{
                conti.first = 1;
                conti.second = c;
            }
            res += c;
            n--;
            if (n!=0) pq.push({n,c});
            
        }
        return res;

    }
};