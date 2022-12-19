class Solution {
private:
    int monotonic_stack(const vector<int>& heights){
        int ans;
        stack<int> mystack;
        int size==heights.size();
        int leftIndex, middleIndex,rightIndex;
        int width, heigh;
        
        for(rightIndex=0; rightIndex<size; rightIndex++){
            while(!mystack.empty() && heights[rightIndex] > heights[mystack.top()]){
                middleIndex = mystack.top();
                mystack.pop();

                if(!mystack.empty()){
                    leftIndex = mystack.top();
                    width = rightIndex - leftIndex - 1;
                    heigh = min(heights[rightIndex], heights[leftIndex]) - heights[middleIndex];
                    ans += width * heigh;
                }
            }
            mystack.push(rightIndex);
        }
    }
public:
    int trap(vector<int>& height) {
        int ans = monotonic_stack(heigh);
        return ans;
    }
};