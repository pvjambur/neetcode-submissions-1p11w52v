class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<>> pq;
        unordered_map<int,int> mp;
        int mx = 0;
        for (int x: hand){
            if (!mp.count(x)){
                pq.push(x);
            }
            mp[x]++;
        }
        while (!pq.empty()){
            int val = pq.top();
            pq.pop();

            if (mp[val]==0) continue;

            int freq = mp[val];

            for (int i=0;i<groupSize;i++){
                int x = val + i;

                if (mp[x]<freq) return false;
                mp[x] -= freq;
            }
        }
        return true;
    }
};
