class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while (columnNumber!=0 && columnNumber!=1){
            int temp = columnNumber%26;
            if (temp==0) res+='Z';
            else res += char(temp-1+'A');
            columnNumber = columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};