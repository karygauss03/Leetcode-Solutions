class Solution {
public:
    typedef struct Node{
        int i;
        int j;
        int state;
        Node(int r, int c, int st) : i(r), j(c), state(st) {}
        Node() : i(0), j(0), state(0) {}
    }Node;

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), bits = 0;
        unordered_map<char, int> keyBit;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (islower(grid[i][j])) {
                    keyBit[grid[i][j]] = bits++;
                }
            }
        }
        
        int mask = (1 << bits) - 1;
        int mask_size = (1 << bits);
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(mask_size, 0)));
        
        Node startPosition;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    startPosition = Node(i, j, 0);
                    break;
                }
            }
        }
        
        queue<Node> q;
        q.push(startPosition);
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz ; ++k) {
                int r = q.front().i;
                int c = q.front().j;
                int state = q.front().state;
                q.pop();
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    continue;   
                }
                if (grid[r][c] == '#') {
                    continue;
                }
                if (isupper(grid[r][c]) && !(state & (1 << keyBit[tolower(grid[r][c])]))) {
                    continue;
                }
                if (islower(grid[r][c])) {
                    state |= (1 << keyBit[grid[r][c]]);
                }
                if (state == mask) {
                    return ans;
                }
                if (vis[r][c][state]) {
                    continue;
                }
                vis[r][c][state] = 1;
                q.push(Node(r + 1, c, state));
                q.push(Node(r - 1, c, state));
                q.push(Node(r, c + 1, state));
                q.push(Node(r, c - 1, state));
            }
            ++ans;
        }
        
        return -1;
    }
};