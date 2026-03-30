class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int n1 = g.size(),n2 =s.size();
        int count=0;
        while (i<n1 && j<n2){
            while (j<n2 && g[i]>s[j]) j++;
            if (j==n2) break;
            if (g[i]<=s[j]) count++;
            i++;
            j++;
        }
        return count;
    }
};