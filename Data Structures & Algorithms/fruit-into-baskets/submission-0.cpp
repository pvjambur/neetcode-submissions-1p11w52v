class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int j=0;
        int n = fruits.size();
        int ans = 0;
        for (int i=0;i<n;i++){
            if (!mp.count(fruits[i]) && mp.size()==2){
                while (j<i && mp.size()==2){
                    mp[fruits[j]]--;
                    if (mp[fruits[j]]==0) mp.erase(fruits[j]);
                    j++;
                }
            }
            mp[fruits[i]]++;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};