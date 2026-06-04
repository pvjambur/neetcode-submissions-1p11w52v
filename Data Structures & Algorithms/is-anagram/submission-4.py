class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        cnt = [0]*26;

        for ch in s:
            cnt[ord(ch) - ord('a')]+=1

        for ch in t:
            cnt[ord(ch) - ord('a')]-=1

        for i in range(0,26):
            if (cnt[i]!=0):
                return False
            
        return True