
// BFS：超时
int MATRIX_X[] = {1, 0, -1, 0};
int MATRIX_Y[] = {0, -1, 0, 1};
const int MATRIX_LEN = 4;
const int MAX_N = 100 + 5;

struct Point{
    int x;
    int y;
    int len;
    Point(int x, int y, int len): x(x), y(y), len(len) {}
};

bool visited[MAX_N][MAX_N];

#define ADD_ACCESS_FLAG(point) visited[point.x][point.y] = true
#define INIT_VISITED(value) memset(visited, value, sizeof(visited))
#define HAS_VISITED(point) visited[point.x][point.y] == true

class Solution {
private:
    static bool is_in_grid(const vector<vector<int>> &grid, Point point){
        return point.x >= 0 && point.y >=0 && point.x < grid.size() && point.y < grid[0].size();
    }

    static bool is_ocean(const vector<vector<int>> &grid, Point point){
        return grid[point.x][point.y] == 0;
    }

    void add_around_point_to_queue(queue<Point> &q, Point point, const vector<vector<int>> &grid){
        for(int i=0; i<MATRIX_LEN; i++){
            Point nextPoint = Point(point.x + MATRIX_X[i], point.y + MATRIX_Y[i], point.len + 1);
            if(is_in_grid(grid, nextPoint) && !HAS_VISITED(nextPoint)){
                ADD_ACCESS_FLAG(nextPoint);
                q.push(nextPoint);
            }
        }
    }

    int bfs(vector<vector<int>> &grid, Point startPoint){
        INIT_VISITED(0);
        ADD_ACCESS_FLAG(startPoint);
        queue<Point> q;
        q.push(startPoint);
        int ans=-1;

        while(!q.empty()){
            Point point = q.front();
            q.pop();

            if(!is_in_grid(grid, point)){
                continue;
            }

            if(is_ocean(grid, point)){
                add_around_point_to_queue(q, point, grid);
            }else{
                ans = point.len;
                break;
            }
        }
        return ans;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int size = grid.size();
        int x, y;
        int ans=-1;

        for(x=0; x<size; x++){
            for(y=0; y<size; y++){
                Point point = Point(x, y, 0);
                
                if(is_ocean(grid, point)){
                    int len = bfs(grid, point);
                    if(len > ans){
                        ans = len;
                    }
                }
            }
        }

        return ans;
    }
};