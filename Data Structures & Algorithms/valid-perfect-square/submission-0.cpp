class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i=1;i*i<=num;i++){
            if (i*i==(long long)num) return true;
        }
        return false;
    }
};