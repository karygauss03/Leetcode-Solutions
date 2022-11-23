class Solution {
public:
    bool isValidSudoku(vector<vector<char>> const & board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool rowCheck[9] = {};
            bool colCheck[9] = {};
            bool boxCheck[9] = {};

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (rowCheck[board[i][j] - '1'])
                        return false;
                    else
                        rowCheck[board[i][j] - '1'] = true;
                }

                if (board[j][i] != '.')
                {
                    if (colCheck[board[j][i] - '1'])
                        return false;
                    else
                        colCheck[board[j][i] - '1'] = true;
                }


                int m = i / 3 * 3 + j / 3;
                int n = i % 3 * 3 + j % 3;

                if (board[m][n] != '.')
                {
                    if (boxCheck[board[m][n] - '1'])
                        return false;
                    else
                        boxCheck[board[m][n] - '1'] = true;
                }

            }
        }
        return true;
    }
};