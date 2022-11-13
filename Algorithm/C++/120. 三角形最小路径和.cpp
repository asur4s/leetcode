// 递归会超时
class Solution {
private:
    int max_value;
    int max_deep;
    void dfs(const vector<vector<int>>& triangle, int j, int k, int value){
        if(j >= max_deep){
            return;
        }
        value = value+triangle[j][k];
        if(j == max_deep - 1){
            max_value = min(max_value, value);
        }
        
        dfs(triangle, j+1, k, value);
        dfs(triangle, j+1, k+1, value);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        max_value = INT_MAX;
        max_deep = triangle.size();
        dfs(triangle, 0, 0, 0);
        return max_value;
    }
};
// 应该采用动态规划