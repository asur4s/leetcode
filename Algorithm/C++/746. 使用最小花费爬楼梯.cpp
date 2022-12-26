class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> spend(size+1, 0);
        int minCost;

        spend[0] = spend[1] = 0;        
        for(int index=2; index < size+1; index++){
            spend[index] = min(spend[index - 1] + cost[index - 1], spend[index - 2] + cost[index - 2]);
        }

        return spend[size];
    }
};