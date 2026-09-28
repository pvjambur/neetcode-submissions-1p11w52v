class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username,
                                       vector<int>& timestamp,
                                       vector<string>& website) {
        
        int n = username.size();

        vector<tuple<int,string,string>> v;
        for (int i=0;i<n;i++){
            v.push_back({timestamp[i], username[i], website[i]});
        }

        sort(v.begin(),v.end());

        map<string,vector<string>> mp;

        for (auto &[t,u,w] : v){
            mp[u].push_back(w);
        }

        map<vector<string>,int> cnt;

        for (auto &[u,sites] : mp){
            int m = sites.size();
            set<vector<string>> seen;

            for (int i=0;i<m;i++){
                for (int j=i+1;j<m;j++){
                    for (int k=j+1;k<m;k++){
                        seen.insert({sites[i],sites[j],sites[k]});
                    }
                }
            }

            for (auto &p : seen){
                cnt[p]++;
            }
        }

        vector<string> ans;
        int best = 0;

        for (auto &[p,c] : cnt){
            if (c > best){
                best = c;
                ans = p;
            }
        }

        return ans;
    }
};