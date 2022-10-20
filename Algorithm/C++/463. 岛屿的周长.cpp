class Solution {
private:
    bool inVector(int r, int j, int n, int m){
        return 0<=r && r<n && 0<=j && j<m;
    }

    int dfs(vector<vector<int>>& grid,int r, int j, int n, int m){
        
        if(!inVector(r, j, n, m)){
            return 1;
        }
        if(grid[r][j] == 0){
            return 1;
        }
        if(grid[r][j] == 2){
            return 0;
        }
        
        grid[r][j] = 2;
        return dfs(grid, r-1, j, n, m) + dfs(grid, r+1, j, n, m) + dfs(grid, r, j-1, n, m) + dfs(grid, r, j+1, n, m);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans;
        int n = grid.size();
        int m = grid[0].size();

        for(int r = 0; r<n; r++){
            for(int j = 0; j<m; j++){
                if(grid[r][j] == 1){
                    return ans = dfs(grid, r, j, n, m);
                }
            }
        }
        return ans;
    }
};