class Solution {
    public:
    bool checkWord(int row, int column, vector<vector<char>>& board, int pos, string word) {
        if (pos == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) return false;
        if (board[row][column] != word[pos]) return false;
        char temp = board[row][column];
        board[row][column] = '-1';
        if (checkWord(row + 1, column, board, pos + 1, word) ||
            checkWord(row - 1, column, board, pos + 1, word) ||
            checkWord(row, column + 1, board, pos + 1, word) ||
            checkWord(row, column - 1, board, pos + 1, word)) {
            return true;
        }
        board[row][column] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && checkWord(i, j, board, 0, word)) return true;
                ;
            }
        }

        return false;
    }
};
