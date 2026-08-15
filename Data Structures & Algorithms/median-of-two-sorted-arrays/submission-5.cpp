class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size();
        int m = nums2.size();

        int l =0;
        int r = n;

        int half = (n+m+1)/2;

        while (l<=r){
            int i = (l+r)/2;
            int j = half - i;

            int left1 = INT_MIN, left2 = INT_MIN;
            int right1 = INT_MAX, right2 = INT_MAX;

            if (i!=0){
                left1 = nums1[i-1];
            }
            if (i!=n){
                right1 = nums1[i];
            }
            if (j!=0){
                left2 = nums2[j-1];
            }
            if (j!=m){
                right2 = nums2[j];
            }

            if (left1<=right2 && left2<=right1){
                if ((m+n)%2==1){
                    return max(left1,left2);
                }
                else{
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
            }

            if (left1>right2){
                r = i-1;
            }
            else{
                l = i+1;
            }
        }
        return 0.0;
        
    }
};
