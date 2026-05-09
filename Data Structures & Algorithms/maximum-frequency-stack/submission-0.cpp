class FreqStack {
private:

    int pos = 0;

    unordered_map<int, priority_queue<int>> mp;

public:

    FreqStack() {
        
    }
    
    void push(int val) {

        mp[val].push(pos++);

    }
    
    int pop() {

        int bestNum = -1;
        int bestFreq = -1;
        int bestPos = -1;

        for (auto &it : mp) {

            int num = it.first;
            auto &pq = it.second;

            if (pq.empty()) continue;

            int freq = pq.size();
            int recentPos = pq.top();

            if (freq > bestFreq) {

                bestFreq = freq;
                bestPos = recentPos;
                bestNum = num;

            }
            else if (freq == bestFreq && recentPos > bestPos) {

                bestPos = recentPos;
                bestNum = num;
            }
        }

        mp[bestNum].pop();

        return bestNum;
    }
};