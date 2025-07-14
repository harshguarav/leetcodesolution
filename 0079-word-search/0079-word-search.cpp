class Solution {
public:
    int m, n;
    
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        if (idx == word.length()) return true; // word mil gaya

        // boundary + visited check + character match check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];      // store current char
        board[i][j] = '*';            // mark visited

        // explore all 4 directions
        bool found = dfs(i+1, j, idx+1, board, word) ||
                     dfs(i-1, j, idx+1, board, word) ||
                     dfs(i, j+1, idx+1, board, word) ||
                     dfs(i, j-1, idx+1, board, word);

        board[i][j] = temp;           // backtrack (unmark)

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};
