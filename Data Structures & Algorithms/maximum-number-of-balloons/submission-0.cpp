class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        int count = INT_MAX;
        for (auto x: text){
            if (mp.find(x)!=mp.end()){
                mp[x]++;
            }
        }
        for (auto [c,n]: mp){
            if (c=='l'|| c=='o'){
                int temp = n/2;
                count = min(count,temp);
            }
            else{
                count = min(count,n);
            }
        }
        return count;
    }
};