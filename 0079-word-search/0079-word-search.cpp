class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        if (!word.size())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        board[i][j] = c;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (dfs(board, i, j, word)) return true;
            }
        }
        return false;
    }
};