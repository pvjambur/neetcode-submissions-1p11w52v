class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars(n);

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // Sort by position descending
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double curTime = 0;

        for (auto &c : cars) {
            if (c.second > curTime) {
                curTime = c.second;
                fleets++;
            }
        }

        return fleets;
    }
};