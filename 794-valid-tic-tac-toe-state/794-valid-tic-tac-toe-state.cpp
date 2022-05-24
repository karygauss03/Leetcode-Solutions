class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX=0, countO=0;
        for (int i =0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                if (board[i][j] == 'X') countX++;
                else if (board[i][j] == 'O') countO++;
            }
        }
    
        if (countX - countO >= 2 || countX - countO < 0) return false;
        
        cout << check(board, 'X') << endl;
        cout << check(board, 'O') << endl;
        
        if (check(board, 'X') > 0 && check(board, 'O') > 0) return false;
        
        if (countX == countO && check(board, 'X') > 0) return false;
        
        if (countX == countO + 1 && check(board, 'O') > 0) return false;
        
        return true;
    }
    
    
    int check(vector<string>& board, char ck) {
        
        int count = 0;
        for (int i = 0; i < 3; ++i){
            count = count + (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == ck);
        }
        
        for (int i = 0; i < 3; ++i){
            count += (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == ck );
        }
        
        count += (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == ck);
        
        count += (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == ck);
        
        return count;
    }
    
};