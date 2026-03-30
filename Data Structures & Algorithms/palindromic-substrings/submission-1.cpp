class Solution {
public:
    int expand(int l, int r, string &s){
        int count = 0;

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            ans += expand(i,i,s);  
            ans += expand(i,i+1,s);   
        }

        return ans;
    }
};