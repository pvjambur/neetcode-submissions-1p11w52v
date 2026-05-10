class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> mp;
        for (int x: students){
            mp[x]++;
        }

        for (int x: sandwiches){
            if (mp[x]==0){
                return mp[0]+mp[1];
            }
            else{
                mp[x]--;
            }
        }
        return 0;
    }
};