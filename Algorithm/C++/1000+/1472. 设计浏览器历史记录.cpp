class BrowserHistory {
private:
    stack<string> backHis;
    stack<string> forwardHis;
    string presentUrl;
public:
    BrowserHistory(string homepage) {
        presentUrl = homepage;
    }
    
    void visit(string url) {
        backHis.push(presentUrl);
        presentUrl = url;
        while(!forwardHis.empty())  forwardHis.pop();
    }
    
    string back(int steps) {
        while(steps-- > 0 && !backHis.empty()){
            forwardHis.push(presentUrl);
            presentUrl = backHis.top();
            backHis.pop();
        }
        return presentUrl;
    }
    
    string forward(int steps) {
        while(steps-- > 0 && !forwardHis.empty()){
            backHis.push(presentUrl);
            presentUrl = forwardHis.top();
            forwardHis.pop();
        }
        return presentUrl;
    }
};