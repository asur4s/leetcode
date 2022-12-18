// 递归
class Solution {
private:
    int maxAns;
    void dfs(const vector<int> &nums, int index, int value){
        if(value > maxAns){
            maxAns = value;
        }

        if(index == nums.size() - 1){
            return;
        }
        dfs(nums, index+1, value*nums[index+1]);
        dfs(nums, index+1, nums[index+1]);
    }

public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        maxAns = INT_MIN;
        dfs(nums, 0, nums[0]);
        return maxAns;
    }
};

// 暴力存储
class Solution {
private:
    int maxAns;
    void updateMaxProduct(int product, int num){
        if(product > maxAns || num > maxAns){
            maxAns = max(product, num);
        }
    }

    void calcAllProduct(queue<int> &preValues, queue<int> &curValues, int num){
        int product;
        while(!preValues.empty()){
            product = num * preValues.front();
            preValues.pop();
            updateMaxProduct(product, num);

            curValues.push(num);
            curValues.push(product); 
        }
        preValues.swap(curValues);
    }
    
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }

        maxAns=nums[0];

        queue<int> preValues;
        queue<int> curValues;
        preValues.push(nums[0]);

        int product;
        for(int i=1; i<size; i++){
            calcAllProduct(preValues, curValues, nums[i]);
        }
        return maxAns;
    }
};



// 动态规划（选择计算，选择最大的和最小的保存）
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }

        int maxAns = nums[0];
        vector<int> maxArr(nums), minArr(nums);
        for(int i=1; i<size; i++){
            maxArr[i] = max({minArr[i-1] * nums[i], nums[i], maxArr[i-1] * nums[i]});
            minArr[i] = min({minArr[i-1] * nums[i], nums[i], maxArr[i-1] * nums[i]});
            
            if(maxArr[i] > maxAns){
                maxAns = maxArr[i];
            }
        }
        return maxAns;
    }
};


// 滚动数组优化
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preMin = nums[0], preMax = nums[0];
        int maxAns = nums[0], size = nums.size();
        int pX, pN;
        for(int i=1; i<size; i++){
            pX = preMax;
            pN = preMin;
            if(nums[i] > 0){
                preMin = min(pN * nums[i], nums[i]);
                preMax = max(pX * nums[i], nums[i]);
            }else{
                preMin = min(pX * nums[i], nums[i]);
                preMax = max(pN * nums[i], nums[i]);
            } 
            if(preMax > maxAns){
                maxAns = preMax;
            }
        }
        return maxAns;
    }
};