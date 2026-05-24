class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({source, 0});

        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;

        visitedStops.insert(source);

        while (!q.empty()){
            auto [stop, busesTaken] = q.front();
            q.pop();

            for (int bus : stopToBus[stop]) {

                if (visitedBuses.count(bus)) continue;

                visitedBuses.insert(bus);

                for (int nextStop : routes[bus]) {

                    if (nextStop == target)
                        return busesTaken + 1;

                    if (!visitedStops.count(nextStop)) {
                        visitedStops.insert(nextStop);
                        q.push({nextStop, busesTaken + 1});
                    }
                }
            }
            
        }
        return -1;

    }
};