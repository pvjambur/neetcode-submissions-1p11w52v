class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while (columnNumber!=0){
            int temp = columnNumber%26;
            res += char(temp-1+'A');
            columnNumber = columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};