class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        long long num11=0,num22=0;
        for (int i=n1-1;i>=0;i--){
            num11 = 10*num11 + (long long)(num1[i]-'0');
        }
        for (int i=n2-1;i>=0;i--){
            num22 = 10*num22 + (long long)(num2[i]-'0');
        }
        long long res = num11*num22;
        string prod="";
        while (res!=0){
            prod += char(res%10 + '0');
            res = res/10;
        }
        reverse(prod.begin(),prod.end());
        return prod;
    }
};
