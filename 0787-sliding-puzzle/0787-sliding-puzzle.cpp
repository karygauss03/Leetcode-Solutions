class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string start, target = "123450";
        for (auto & row: board)
            for (int cell: row) start += to_string(cell);
        unordered_set < string > seen;
        queue < string > q;
        q.push(start), seen.insert(start);
        for (int moves = 0; !q.empty(); ++moves) {
            for (int n = q.size(); n--;) {
                auto cur = q.front();
                q.pop();
                if (cur == target) return moves;
                int zero = cur.find('0');
                for (int d: dirs[zero]) {
                auto next = cur;
                swap(next[zero], next[d]);
                if (seen.count(next)) continue;
                seen.insert(next), q.push(next);
                }
            }
            }
            return -1;
        }
};
