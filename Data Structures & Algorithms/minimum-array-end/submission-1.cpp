class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long add = n - 1;

        int bit = 0;

        while (add > 0) {
         
            if (((res >> bit) & 1) == 0) {

                if (add & 1) {
                    res |= (1LL << bit);
                }
                add >>= 1;
            }
            bit++;
        }

        return res;
    }
};