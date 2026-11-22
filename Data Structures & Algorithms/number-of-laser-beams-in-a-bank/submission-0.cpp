class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, cur = 0, res = 0;
        for (auto& row: bank){
            int temp =0;    
            for (char c: row){
                if (c=='1') temp++;
            }

            if (temp==0) continue;
            prev = cur;
            cur = temp;
            res += prev*cur;
        }
        return res;
    }
};