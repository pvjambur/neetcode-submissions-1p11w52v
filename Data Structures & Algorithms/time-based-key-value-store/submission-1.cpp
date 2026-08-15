class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        string ans = "";
        int r = mp[key].size()-1;
        if (r==-1) return ans;

        while (l<=r){
            int mid = (l+r)/2;
            if (mp[key][mid].first<=timestamp){
                ans = mp[key][mid].second;
                l = mid+1;

            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
