class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j =0;
        int changes = INT_MAX;
        int temp = 0;
        for (int i=0;i<blocks.size();i++){
            if (blocks[i]=='W') temp++;
            if (i - j + 1==k){
                changes = min(changes, temp);
                if (blocks[j]=='W') temp--;
                j++;
            }
        }
        return changes;
    }
};