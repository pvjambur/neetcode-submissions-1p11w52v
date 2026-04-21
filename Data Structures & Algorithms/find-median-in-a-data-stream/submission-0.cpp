class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        vector<int> v;
        while (!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        double res=0;
        int n = v.size();
        int t1 = v[n/2];
        int t2 = v[(n/2)-1];
        if (n%2==1) res = (double)(t1);
        else res = ((double)(t1+t2))/2;
        for (auto x: v){
            pq.push(x);
        }
        return res;
    }
};
