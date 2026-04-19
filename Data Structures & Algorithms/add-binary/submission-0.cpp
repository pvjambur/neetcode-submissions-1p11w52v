class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        char carry = '0';
        string res="";
        while (n1>=0 && n2>=0){
            if (a[n1]=='1' && b[n2]=='1'){
                if (carry=='0'){
                    res+='0';
                    carry='1';
                }
                else{
                    res+='1';
                }
            }
            else if ((a[n1]=='1' && b[n2]=='0') || (a[n1]=='0' && b[n2]=='1')){
                if (carry=='0'){
                    res+='1';
                    carry='0';
                }
                else{
                    res+='0';
                    carry = '1';
                }
            }
            else{
                if (carry=='0'){
                    res+='0';
                }
                else{
                    res+='1';
                    carry = '0';
                }
            }
            n1--;
            n2--;
        }
        while (n1>=0){
            if (a[n1]=='1'){
                if (carry=='0'){
                    res+='1';
                }
                else{
                    res+='0';
                    carry='1';
                }
            }
            else{
                if (carry=='0'){
                    res+='0';
                }
                else{
                    res+='1';
                    carry = '0';
                }
            }
            n1--;
        }

        while (n2>=0){
            if (a[n2]=='1'){
                if (carry=='0'){
                    res+='1';
                }
                else{
                    res+='0';
                    carry='1';
                }
            }
            else{
                if (carry=='0'){
                    res+='0';
                }
                else{
                    res+='1';
                    carry = '0';
                }
            }
            n2--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};