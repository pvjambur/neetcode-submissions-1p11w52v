class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;

        while (l<r){
            while (l<n-1 && !isdigit(s[l]) && !islower(s[l]) && !isupper(s[l])) l++;
            while (r>=1 && !isdigit(s[r]) && !islower(s[r]) && !isupper(s[r])) r--;

            if (l>=r) return true;

            if (s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            else{
                bool t1 = isdigit(s[l]);
                bool t2 = isdigit(s[r]);

                if ((t1 && !t2) || (!t1 && t2)) return false;

                else if (t1 && t2){
                    if (s[l]==s[r]){
                        l++;
                        r--;
                        continue;
                    }
                    else{
                        return false;
                    }
                }

                char c1 = tolower(s[l]);
                char c2 = tolower(s[r]);

                if (c1!=c2) return false;
                else{
                    l++;
                    r--;
                    continue;
                }
            }
        }

        return true;
    }
};
