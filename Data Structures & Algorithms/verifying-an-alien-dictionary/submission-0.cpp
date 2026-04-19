class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26] = {0};
        for (int i=0;i<26;i++){
            arr[i] = (order[i] - 'a');
        }
        int n = words.size();
        vector<int> len;
        int val = 0;
        for (int i=0;i<words[0].size();i++){
            val += arr[words[0][i]];
        }
        len.push_back(val);
        for (int i=1;i<n;i++){
            if (words[i].size()<words[i-1].size()) return false;
            int val1 = 0;
            for (int j=0;i<words[j].size();j++){
                val1 += arr[words[i][j]];
            }
            if (val1<len.back()) return false;
        }
        return true;
    }
};