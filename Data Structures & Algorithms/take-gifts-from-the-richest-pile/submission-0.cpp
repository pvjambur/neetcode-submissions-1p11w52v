class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for (int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        long long total = 0;
        while (k--){
            long long temp = pq.top();
            pq.pop();
            temp = (long long)floor(sqrt(temp));
            pq.push(temp);
        }
        while (!pq.empty()){
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};