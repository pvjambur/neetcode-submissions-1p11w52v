class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
          
            char p1 = (i % 2 == 0) ? '0' : '1';
            if (s[i] != p1) cnt1++;

       
            char p2 = (i % 2 == 0) ? '1' : '0';
            if (s[i] != p2) cnt2++;
        }

        return min(cnt1, cnt2);
    }
};