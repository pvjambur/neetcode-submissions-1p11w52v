class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto s: details){
            int temp = (int)(s[11]-'0')*10 + (int)(s[12]-'0');
            if (temp>60) count++;

        }
        return count;
    }
};