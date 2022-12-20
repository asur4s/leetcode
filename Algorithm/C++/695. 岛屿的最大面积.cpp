struct Point{
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
};
int MATRIX_X[4] = {0, 0, 1, -1};
int MATRIX_Y[4] = {1, -1, 0, 0};

class Solution {
private:
    bool is_land(const vector<vector<int>> &grid, const Point &point){
        return grid[point.x][point.y] == 1;
    }

    bool is_in_grid(const vector<vector<int>> &grid, const Point &point){
        return point.x >= 0 && point.y >= 0 && point.x < grid.size() && point.y < grid[0].size();
    }

    void add_around_point_to_queue(const vector<vector<int>> &grid, Point &point, queue<Point> &q){
        int x, y;
        for (int index = 0; index != 4; ++index) {
            int x = point.x + MATRIX_X[index];
            int y = point.y + MATRIX_Y[index];
            q.push(Point(x, y));
        }
    }

    int bfs(vector<vector<int>> &grid, Point &startPoint){
        queue<Point> q;
        q.push(startPoint);

        int area = 0;
        while (!q.empty()) {
            Point point = q.front();
            q.pop();

            if (is_in_grid(grid, point) && is_land(grid, point)){
                grid[point.x][point.y] = 0;
                add_around_point_to_queue(grid, point, q);
                area++;
            }
        }
        return area; 
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int cur;
        for (int x = 0; x != grid.size(); x++) {
            for (int y = 0; y != grid[0].size(); y++) {
                Point point = Point(x, y);
                cur = bfs(grid, point);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};