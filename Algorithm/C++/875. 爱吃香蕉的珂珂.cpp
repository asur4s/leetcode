class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }

        while (left <= right) {
            int mid = (right - left) / 2 + left;
            long time = getTime(piles, mid);
            if (time <= h) {  // target speed in left 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    long getTime(const vector<int>& piles, int speed) {
        long time = 0;
        for (int pile : piles) {
            int curTime = (pile + speed - 1) / speed;
            time += curTime;
        }
        return time;
    }
};