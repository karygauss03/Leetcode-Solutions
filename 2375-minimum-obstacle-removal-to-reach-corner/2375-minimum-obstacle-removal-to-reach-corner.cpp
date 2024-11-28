class Solution {
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    const int INF = 1e9;

    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({dist[0][0] , 0, 0});
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            if (cur[1] == n - 1 && cur[2] == m - 1) {
                return cur[0];
            }
            for (int i = 0; i < 4; ++i) {
                int x = cur[1] + dir[i][0];
                int y = cur[2] + dir[i][1];
                if (!check(x, y)) continue;
                int cnt = cur[0] + grid[x][y];
                if (cnt < dist[x][y]) {
                    dist[x][y] = cnt;
                    pq.push({cnt, x, y});
                }
            }
        }

        return 0;
    }
};