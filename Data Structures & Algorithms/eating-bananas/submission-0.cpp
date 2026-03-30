class Solution {
private:
    int reqhours(vector<int>& piles, int k) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + k - 1) / k; 
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        while (i < j) {
            int mid = i + (j - i) / 2;
            int hour = reqhours(piles, mid);

            if (hour <= h) {
                j = mid;        
            } else {
                i = mid + 1;    
            }
        }
        return i;
    }
};
