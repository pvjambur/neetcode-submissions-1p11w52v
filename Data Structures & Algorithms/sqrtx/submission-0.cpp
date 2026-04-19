class Solution {
public:
    int mySqrt(int x) {
        for (int i=0;i<=(x/2);i++){
            if (i*i==x) return i;
            else if (i*i>x && i!=0) return i-1;
        }
    }
};