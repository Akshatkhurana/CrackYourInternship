class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,
             vector<vector<bool>>& vis, int i, int j, int ptr) {

        if (ptr == word.length()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            vis[i][j] || board[i][j] != word[ptr]) {
            return false;
        }
        vis[i][j] = true;
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            
            if (dfs(board, word, vis, nrow, ncol, ptr + 1)) {
                return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (dfs(board, word, vis, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

