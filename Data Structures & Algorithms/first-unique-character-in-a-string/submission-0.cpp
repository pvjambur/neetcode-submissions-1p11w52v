class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alpha(26,-1);
        for (int i=0;i<s.size();i++){
            if (alpha[s[i]-'a']==-2) continue;
            else if (alpha[s[i]-'a']==-1) alpha[s[i]-'a']=i;
            else alpha[s[i]-'a']=-2;
        }
        int ind = INT_MAX;
        for (int i=0;i<26;i++){
            if (alpha[i]==-1 || alpha[i]==-2) continue;
            ind = min(ind,alpha[i]);
        }
        return (ind==INT_MAX) ? -1 : ind;
    }
};