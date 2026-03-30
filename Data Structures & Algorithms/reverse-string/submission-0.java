class Solution {
    public void reverseString(char[] s) {
        int i = 0;
        char temp;
        int n = s.length;
        while (i<(n/2)){
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
            i++;
        }
     
    }
}