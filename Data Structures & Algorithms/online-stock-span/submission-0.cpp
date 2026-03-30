class StockSpanner {
public:
    stack<int> master;
    stack<int> temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        master.push(price);
        temp = master;
        int count=0;
        while (!temp.empty() && price>=temp.top()){
            count++;
            temp.pop();
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */