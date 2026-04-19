class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int arr[26] = {0};
        int maxlen = 0;
        int maxfreq=0;
        for (int r=0;r<s.size();r++){
            arr[s[r]-'A']++;
            maxfreq = max(maxfreq,arr[s[r]-'A']);
            while ((r-l+1)-maxfreq>k){
                l++;
                arr[s[l]-'A']--;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
