class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(3,0);
        for (int i=0;i<bills.size();i++){
            if (bills[i]==5){
                cash[0]++;
                continue;
            }
            else if (bills[i]==10){
                int temp = bills[i];
                while (temp>5 && cash[0]>0){
                    temp = temp-5;
                    cash[0]--;
                }
                if (temp==5){
                    cash[1]++;
                    continue;
                }
                return false;
            }
            else{
                int temp = bills[i];
                while (temp>10 && cash[1]>0){
                    temp = temp-10;
                    cash[1]--;
                }
                if (temp==5){
                    cash[2]++;
                    continue;
                }
                while (temp>5 && cash[0]>0){
                    temp = temp-5;
                    cash[0]--;
                }
                if (temp==5){
                    cash[2]++;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};