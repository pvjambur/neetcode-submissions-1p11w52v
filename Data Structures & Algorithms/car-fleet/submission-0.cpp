class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars(n);

        for (int i=0;i<n;i++){
            int time = (double)((target-position[i])/speed[i]);
            cars.push_back({position[i],time});
        }

        sort(cars.rbegin(),cars.rend());
        int fleets=0;
        int curtime=0;
        for (auto &c: cars){
            if (c.second>curtime){
                curtime = c.second;
                fleets++;
            }
        }
        return fleets;
    }
};
