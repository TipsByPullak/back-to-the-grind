class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // first check rows
        unordered_set<int> check;

        for(int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                if (check.find(board[i][j]) != check.end())
                {
                    // cout << "returned here 1: " << i << " " << j << " " << board[i][j] << endl;
                    return false;
                }
                else
                {
                    // cout << "insert 1: " << i << " " << j << " " << board[i][j] << endl;
                    check.insert(board[i][j]);
                }
            }

            check.clear();
        }

        check.clear();

        // check columns
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }

                if (check.find(board[j][i]) != check.end())
                {
                    // cout << "returned here 2: " << endl;
                    return false;
                }
                else
                {
                    check.insert(board[j][i]);
                }
            }
            
            check.clear();
        }

        check.clear();

        // check 3x3
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                for(int k = i; k < 3; ++k)
                {
                    for(int m = j; m < 3; ++m)
                    {
                        if (board[k][m] == '.')
                        {
                            continue;
                        }

                        if (check.find(board[k][m]) != check.end())
                        {
                            // cout << "returned here 3: " << endl;
                            return false;
                        }
                        else
                        {
                            check.insert(board[k][m]);
                        }
                    }
                }
                
                check.clear();
            }
        }

        check.clear();

        return true;
    }
};
