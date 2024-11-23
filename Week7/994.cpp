class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh_count = 0, time = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if (grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }

        if(fresh_count == 0) return 0;

        //BFS
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(!q.empty()){
            int q_size = q.size();
            bool has_rotted = false;
            for(int i = 0; i < q_size; i++){
                auto[x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions){
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh_count--;
                        has_rotted = true;
                    }
                }
            }
            if (has_rotted) time++;
        }
        return fresh_count == 0 ? time : -1;
    }      
};