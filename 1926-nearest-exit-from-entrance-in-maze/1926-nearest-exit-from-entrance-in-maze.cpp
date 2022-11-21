class Solution {
public:
    int n, m;
    bool valid(int x, int y){
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    bool check (pair<pair<int, int>, int>& x){
        if (x.first.first == n -1 || x.first.first == 0 || x.first.second == m - 1 ||x.first.second == 0){
            return true;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size();
        m = maze[0].size();
        int entrance_x = entrance[0], entrance_y = entrance[1];
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<pair<pair<int,int>, int>> q;
        q.push({{entrance_x, entrance_y}, 0});
        map<pair<int, int>, bool> ma;
        ma[make_pair(entrance_x, entrance_y)] = true;
        while (!q.empty()){
            auto x = q.front();
            if (check(x) && x.first != make_pair(entrance_x, entrance_y)){
                return x.second;
            }
            q.pop();
            for (int i = 0 ; i < 4 ; i++){
                if (valid(x.first.first + dx[i],x.first.second + dy[i]) && ma.find(make_pair(x.first.first + dx[i], x.first.second + dy[i])) == ma.end() && maze[x.first.first + dx[i]][x.first.second + dy[i]] != '+'){
                    q.push({{x.first.first + dx[i], x.first.second + dy[i]}, x.second + 1});
                    ma[make_pair(x.first.first + dx[i], x.first.second + dy[i])] = true;
                }
            }
        }
        return -1;
    }
};