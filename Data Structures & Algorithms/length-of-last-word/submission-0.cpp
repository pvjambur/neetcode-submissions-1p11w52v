class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        string res="";
        int count=0;
        while (i>=0){
            while (i>=0 && s[i]==' ') i--;
            while (i>=0 && s[i]!=' '){
                count++;
                i--;
            }
            if (i>=0 && s[i]==' ') break;

        }
        return count;
    }
};