class Solution {
private:
    void updateNum(int len,  int num, int &curLen, int &curLenNum){
        if (len == curLen) {
            curLenNum += num;
        }
    }

    void resetLenAndNum(int len, int num, int &curLen, int &curLenNum){
        if (len > curLen) {
            curLen = len;
            curLenNum = num; 
        }
    }
public:
    int findNumberOfLIS(vector<int> &nums) {
        int size = nums.size();
        vector<int> lenArr(size, 1), numArr(size, 1);
        int maxLen = 0, maxLenNum = 0;

        for (int endIndex = 0; endIndex < size; ++endIndex) {
            for (int index = 0; index < endIndex; ++index) {
                if (nums[endIndex] > nums[index]) {
                    updateNum(lenArr[index] + 1, numArr[index],  lenArr[endIndex], numArr[endIndex]);
                    resetLenAndNum(lenArr[index] + 1, numArr[index],  lenArr[endIndex], numArr[endIndex]);
                }
            }
            updateNum(lenArr[endIndex], numArr[endIndex], maxLen, maxLenNum);
            resetLenAndNum(lenArr[endIndex], numArr[endIndex], maxLen, maxLenNum);
        }
        return maxLenNum;
    }
};