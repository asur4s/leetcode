class StockSpanner {
private:
    stack<pair<int, int>> mystack;

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;
        while(!mystack.empty() && price >= mystack.top().first){
            cnt += mystack.top().second;
            mystack.pop();
        }
        mystack.push({price, cnt});
        return cnt;
    }
};
