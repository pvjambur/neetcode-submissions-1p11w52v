class UndergroundSystem {
private:
    unordered_map<long long,pair<long long,int>> time_mp;
    unordered_map<int,pair<string,int>> jrny_mp;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        jrny_mp[id] = {stationName,t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [src,t1] = jrny_mp[id];
        jrny_mp.erase(id);

        long long key = 0;
        for (char c : src) key = key * 31 + c;
        key = key * 31 + '#';
        for (char c : stationName) key = key * 31 + c;

        time_mp[key].first += t - t1;
        time_mp[key].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        long long key = 0;
        for (char c : startStation) key = key * 31 + c;
        key = key * 31 + '#';
        for (char c : endStation) key = key * 31 + c;

        auto [tot,freq] = time_mp[key];
        return (double)tot/freq;
    }
};