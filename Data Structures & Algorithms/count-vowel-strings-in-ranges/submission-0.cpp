class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string temp = "";
        vector<int> res;
        unordered_set<char> st = {'a','e','i','o','u'};
        for (auto &s: words){
            if (st.count(s[0]) && st.count(s[s.size()-1])){
                temp += '1';
            }
            else{
                temp += '0';
            }
        }

        for (auto &v: queries){
            int l = v[0];
            int r = v[1];
            int count = 0;
            while (l<=r){
                if (l==r && temp[l]=='1'){
                    count++;
                    break;
                }


                if (temp[l]=='1') count++;
                if (temp[r]=='1') count++;
                l++;
                r--;
            }
            res.push_back(count);
        }

        return res;
    }
};