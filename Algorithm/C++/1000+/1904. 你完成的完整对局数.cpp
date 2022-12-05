class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int t0 = 60 * stoi(loginTime.substr(0, 2))+ stoi(loginTime.substr(3, 2));
        int t1 = 60 * stoi(logoutTime.substr(0, 2))+ stoi(logoutTime.substr(3, 2));
        if(t1 < t0){
            t1 = t1 + 24 * 60;
        }
        t1 = t1 / 15 * 15;
        return max(0, (t1 - t0)/15);
    }
};