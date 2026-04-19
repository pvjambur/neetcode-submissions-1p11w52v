class Solution {
private:
    int check_pali(int l, int r, string& s){
        int flag=1;
        if (l>r || r<0 || l<0 || r>=s.size() || l>=s.size()) return 0;
        if (l==r) return 1;
        int m=l;
        int n=r;
        while (m<=n){
            if (s[m]!=s[n]){
                flag=0;
                break;
            }
            m++;
            n--;
        }
        if (flag==1){
            return (1 + check_pali(l+1,r,s) + check_pali(l,r-1,s));
        }
        return (check_pali(l+1,r,s) + check_pali(l,r-1,s));
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        return check_pali(l,r,s)-1;
    }
};
