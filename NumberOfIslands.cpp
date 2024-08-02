class Solution {
public:
    void visited(vector<vector<char>>& grid, int i, int j, int row, int col) {
        if (i >= row || i < 0 || j < 0 || j >= col || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        visited(grid, i + 1, j, row, col);
        visited(grid, i - 1, j, row, col);
        visited(grid, i, j + 1, row, col);
        visited(grid, i, j - 1, row, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    visited(grid, i, j, row, col);
                    count = count + 1;
                }
            }
        }
        return count;
    }
};
