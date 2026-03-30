class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for (int i=m;i<m+n;i++){
            nums1[i] = nums2[j];
            j++;
        }

        for (int i=m;i<m+n;i++){
            int j = i;
            while (j>=1 && nums1[j]<nums1[j-1]){
                swap(nums1[j],nums1[j-1]);
                j--;
            }
        }
    }
};