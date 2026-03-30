class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i=0;i<n1;i++){
            s1.insert(nums1[i]);
        }
        for (int i=0;i<n2;i++){
            s2.insert(nums2[i]);
        }
        vector<vector<int>> res(2);
        for (auto p: s1){
            if (s2.find(p)==s2.end()) res[0].push_back(p);
        }
        for (auto p: s2){
            if (s1.find(p)==s1.end()) res[1].push_back(p);
        }
        return res;
    }
};