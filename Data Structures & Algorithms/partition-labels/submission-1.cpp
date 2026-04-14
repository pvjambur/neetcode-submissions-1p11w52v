class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int arr[26] = {0};
        for (int i=0;i<n;i++){
            arr[s[i]-'a'] = i;
        }
        vector<int> res;
        int end = 0,start=0;
        for (int i=0;i<n;i++){
            end = max(end,arr[s[i]-'a']);

            if (i==end){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;

    }
};
