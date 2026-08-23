class Solution {
bool check(int mid, vector<int>& weights, int days){
    int cur = 0;
    int count = 0;
    for (int x: weights){
        cur+=x;
        if (cur>mid){
            cur = x;
            count++;
        }
        if (count>=days){
            return false;
        }
    }
    return true;
}

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r =0;
        for (int x: weights){
            r+=x;
        }

        while (l<r){
            int mid = (l+r)/2;

            if (check(mid,weights,days)){
                r = mid;
            }           
            else{
                l = mid+1;
            }       
        }
        return l;
    }
};