class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int k = s1.length();
        int[] mp = new int[26];
        int[] mp_dup = new int[26];
        for (int i=0;i<k;i++){
                mp[s1.charAt(i)-'a']++;
                mp_dup[s1.charAt(i)-'a']++;
        }
        int n = s2.length();
        if (n<k) return false;
        for (int i=0;i<=n-k;i++){
            int flag=0;
            for (int j=i;j<i+k;j++){
                mp_dup[s2.charAt(j)-'a']-=1;
            }
            for (int j=0;j<26;j++){
                if (mp_dup[j]!=0){
                    flag=1;
                    break;
                }
            }
            if (flag==0) return true;
            else{
                for (int j=0;j<26;j++){
                    mp_dup[j]=mp[j];
                }
            }
        }
        return false;
    }
}
