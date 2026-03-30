class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n==1) return 1;
        vector<int> arr(256);
        fill(arr.begin(),arr.end(),0);
        int i = 0;
        int j = 0;
        int lent = 0;
        while (i<n && j<n){
            if (arr[s[j]]==0){
                arr[s[j]]++;
                lent = max(lent,j-i+1);
                j++;
            }
            else{
                arr[s[i]]--;
                i++;
            }

        }
        return lent;

    }
};
