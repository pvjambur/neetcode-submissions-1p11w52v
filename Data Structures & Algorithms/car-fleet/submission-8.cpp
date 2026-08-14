class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> res(n);

        for (int i=0;i<n;i++){
            double time = (double)(target - position[i])/speed[i];
            res[i] = {position[i],time};
        }

        sort(res.rbegin(),res.rend());

        int fleets = 0;
        double last_time = 0.0;

        for (auto &[pos,time]: res){
            if (time>last_time){
                fleets++;
                last_time = time;
            }
        }
        return fleets;
    }
};
