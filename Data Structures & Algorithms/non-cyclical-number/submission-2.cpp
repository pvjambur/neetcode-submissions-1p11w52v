class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> digits;
        int s_sum=0;
        while (true){
            while (n!=0){
                int temp = n%10;
                s_sum+=temp*temp;
                n=n/10;
            }
            if (s_sum==1) return true;
            if (digits.find(s_sum)!=digits.end()) return false;
            digits.insert(s_sum);
            s_sum=0;
        }
        return false;
    }
};
