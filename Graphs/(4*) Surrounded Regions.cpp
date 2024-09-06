/**
/* Problem link: https://leetcode.com/problems/surrounded-regions/description/
**/

//TC: O(M * N), SC: O(1)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        char TEMP = 'Y';
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[row].size(); col++) {
                if(row == 0 || col == 0 || row == board.size() - 1 || col == board[0].size() - 1) {
                    helper(board, row, col, TEMP);
                }
            }
        }

        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[row].size(); col++) {
                if(board[row][col] == TEMP) {
                    board[row][col] = 'O';
                }
                else {
                    board[row][col] = 'X';
                }
            }
        }
    }

private:
    void helper(vector<vector<char>>& board, int row, int col, char& TEMP) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || board[row][col] != 'O') {
            return;
        }
        board[row][col] = TEMP;
        helper(board, row + 1, col, TEMP);
        helper(board, row, col + 1, TEMP);
        helper(board, row - 1, col, TEMP);
        helper(board, row, col - 1, TEMP);
    }
};
