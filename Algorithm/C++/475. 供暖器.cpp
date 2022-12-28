class Solution {
private:
    int getRightHeater(vector<int> &heaters, int house){
        int heaterPos = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
        return heaterPos;
    }
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());

        for (int house: houses) {
            int rightHeaterPos = getRightHeater(heaters, house);
            int leftHeaterPos = rightHeaterPos - 1;

            int rightDistance = rightHeaterPos >= heaters.size() ? INT_MAX: heaters[rightHeaterPos] - house;
            int leftDistance = leftHeaterPos < 0 ? INT_MAX : house - heaters[leftHeaterPos];

            int curDistance = min(leftDistance, rightDistance);
            ans = max(ans, curDistance);
        }
        return ans;
    }
};