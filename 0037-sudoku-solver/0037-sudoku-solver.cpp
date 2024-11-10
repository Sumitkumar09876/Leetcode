class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize bitsets for rows, columns, and boxes
        memset(rowUsed, 0, sizeof(rowUsed));
        memset(colUsed, 0, sizeof(colUsed));
        memset(boxUsed, 0, sizeof(boxUsed));
        emptyCells.clear();
        
        // Preprocess the board
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    emptyCells.emplace_back(i, j);
                } else {
                    int num = board[i][j] - '1';
                    int k = (i / 3) * 3 + (j / 3);
                    rowUsed[i] |= (1 << num);
                    colUsed[j] |= (1 << num);
                    boxUsed[k] |= (1 << num);
                }
            }
        }
        
        // Start solving
        solve(board, 0);
    }

private:
    int rowUsed[9], colUsed[9], boxUsed[9];
    vector<pair<int, int>> emptyCells;
    bool solved = false;

    bool solve(vector<vector<char>>& board, int pos) {
        if(pos == emptyCells.size()) {
            solved = true;
            return true;
        }

        // Get the position of the next empty cell
        int i = emptyCells[pos].first;
        int j = emptyCells[pos].second;
        int k = (i / 3) * 3 + (j / 3);

        // Compute possible candidates
        int used = rowUsed[i] | colUsed[j] | boxUsed[k];
        for(int num = 0; num < 9; ++num) {
            if(!(used & (1 << num))) {
                // Place the number
                board[i][j] = num + '1';
                rowUsed[i] |= (1 << num);
                colUsed[j] |= (1 << num);
                boxUsed[k] |= (1 << num);

                // Recursive call
                if(solve(board, pos + 1))
                    return true;

                // Backtrack
                board[i][j] = '.';
                rowUsed[i] &= ~(1 << num);
                colUsed[j] &= ~(1 << num);
                boxUsed[k] &= ~(1 << num);
            }
        }
        return false;
    }
};