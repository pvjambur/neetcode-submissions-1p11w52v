class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int j = 0, count = 0;
        int tot = 0;
        int n = arr.size();
        for (int i=0;i<n;i++){
            if ((i-k)>=0){
                int avg = (tot)/k;
                if (avg>=threshold) count++;
                tot = tot - arr[j++];
            }
            tot += arr[i];
        }
        int avg = (tot)/k;
        if (avg>=threshold) count++;
        tot = tot - arr[j++];
        return count;
    }
};