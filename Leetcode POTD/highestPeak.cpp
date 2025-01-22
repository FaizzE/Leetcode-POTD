typedef pair<int, int> pr;
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, -1));
        queue<pr> q;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(isWater[r][c] == 1) {
                    heights[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        while(!q.empty()) {
            pr current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            for(auto &d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && heights[nx][ny] == -1) {
                    heights[nx][ny] = heights[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return heights;
    }
};
