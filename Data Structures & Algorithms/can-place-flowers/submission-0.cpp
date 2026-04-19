class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i=0;i<flowerbed.size();i++){
            if (flowerbed[i]==0){
                if (i>=1 && flowerbed[i-1]==1) continue;
                if (i<=m-2 && flowerbed[i+1]==1) continue;
                n--;
            }
            if (n==0) return true;
        }
        if (n!=0) return false;
        return true;
    }
};