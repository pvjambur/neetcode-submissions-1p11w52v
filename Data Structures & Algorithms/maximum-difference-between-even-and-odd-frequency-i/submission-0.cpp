class Solution {
public:
    int maxDifference(string s) {
        int max_odd = INT_MIN;
        int min_even = INT_MAX;
        unordered_map<char,int> mp;
        for (auto x: s){
            mp[x]++;
        }
        for (auto [x,y]: mp){
            if (y%2==1){
                max_odd = max(max_odd,y);
            }
            else{
                min_even = min(min_even,y);
            }
        }
        return max_odd - min_even;
    }
};