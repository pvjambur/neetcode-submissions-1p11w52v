class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        int flag=0;
        while (l<r){
            if (s[l]!=s[r]){
                if (flag==1) return false;
                flag=1;
                if (s[l+1]==s[r]){
                    l+=2;
                    continue;
                }
                else if (s[l]==s[r-1]){
                    r-=2;
                    continue;
                }
                else return false;
            }
            l++;
            r--;
        }
        return true;
    }
};