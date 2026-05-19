class Solution {
public:

    vector<string> res;

    void backTrack(int ind, int level, string s, string temp){
        int rem = s.size() - ind -1;
        if (level==0){
            if (rem<=2){
                if (s[ind]=='0' && rem!=0) return;
                string ad = s.substr(ind,rem+1);
                int ad1 = stoi(ad);
                if (ad1<0 || ad1>255) return;
                temp += ad;
                res.push_back(temp);
            }
            return;
        }
        int max_lim = 3;
        if (s[ind]=='0') max_lim = 1;

        for (int i=ind;i<ind+max_lim;i++){
            int rem1 = s.size() - i -1;
            string check = s.substr(ind,i-ind+1);
            int check1 = stoi(check);
            if (check1<0 || check1>255) continue;
            temp += s[i];
            if (rem1<level || rem1>(level*3)) continue;
            temp+='.';
            backTrack(i+1,level-1,s,temp);
            temp.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        string temp = "";
        backTrack(0,3,s,temp);
        return res;

    }
};