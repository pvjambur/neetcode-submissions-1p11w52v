class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for s in strs:
            cnt = [0]*26;
            for c in s:
                cnt[ord(c)-ord('a')]+=1
            code = ""
            for i in range(0,26):
                code += str(cnt[i]) + '#'
            
            mp[code].append(s)

        res = []

        return list(mp.values())
