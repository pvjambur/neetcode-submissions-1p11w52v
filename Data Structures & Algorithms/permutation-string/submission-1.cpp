class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp_dup;
        int n1 = s1.size();
        int n2 = s2.size();
        for (int i=0;i<n1;i++){
            mp[s1[i]]++;
            mp_dup[s1[i]]++;
        }
        if (n2<n1) return false;
        for (int i=0;i<=n2-n1;i++){
            if (mp.find(s2[i])!=mp.end()){
                int flag=0;
                for (int j=i;j<i+n1;j++){
                    if (mp_dup.find(s2[j])==mp_dup.end()){
                        flag=1;
                        break;
                    }
                    mp_dup[s2[j]]--;
                }
                if (flag==0){
                for (auto &p : mp_dup) {
                    if (p.second != 0) {
                        flag = 1;
                        break;
                    }
                }
                }

                if (flag==0) return true;
                else{
                    mp_dup = mp;
                }
            }
        }
        return false;
    }
};
