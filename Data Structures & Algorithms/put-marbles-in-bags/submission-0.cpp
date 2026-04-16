class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
    
    vector<int> pairSum;
    for (int i = 0; i < n - 1; i++) {
        pairSum.push_back(weights[i] + weights[i + 1]);
    }

    // Max heap for smallest (k-1)
    priority_queue<int> maxh;
    
    // Min heap for largest (k-1)
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int x : pairSum) {
        maxh.push(x);
        minh.push(x);

        if (maxh.size() > k - 1) maxh.pop(); // keep smallest
        if (minh.size() > k - 1) minh.pop(); // keep largest
    }

    long long minSum = 0, maxSum = 0;

    while (!maxh.empty()) {
        minSum += maxh.top();
        maxh.pop();
    }

    while (!minh.empty()) {
        maxSum += minh.top();
        minh.pop();
    }

    return maxSum - minSum;
    }
};