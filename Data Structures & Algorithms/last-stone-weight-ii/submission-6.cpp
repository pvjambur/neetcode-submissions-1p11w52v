class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int num: stones){
            maxHeap.push(num);
        }

        while (maxHeap.size()>=2){
            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();
            if (s1==s2) continue;
            else if (s1>s2){
                maxHeap.push(s1-s2);
                pq.push(s1-s2);
            }
            else{
                maxHeap.push(s2-s1);
                pq.push(s2-s1);
            }
        }
        if (!maxHeap.size()) return 0;
        if (!pq.size() && maxHeap.size()) return maxHeap.top();
        return pq.top();
    }
};