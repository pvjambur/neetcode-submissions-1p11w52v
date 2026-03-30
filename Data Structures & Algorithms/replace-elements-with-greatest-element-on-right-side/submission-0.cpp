class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        int max_ele=INT_MIN;
        res.push_back(-1);
        for (int i=n-1;i>=1;i--){
            max_ele = max(max_ele,arr[i]);
            res.push_back(max_ele);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};