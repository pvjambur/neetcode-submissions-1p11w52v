class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return (double)(1);
        int check=0;
        if (n<0){
            check=1;
            n = (int)(n*-1);
        }
        double res=1;
        while (n!=0){
            res*=x;
            n=n-1;
        }
        if (check==1) return (1/res);
        return res;
    }
};
