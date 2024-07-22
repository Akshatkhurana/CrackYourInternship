class Solution {
public:
    int solve(int row, int col, int i, int j, int delRow[], int delCol[],vector<vector<int>> &dp) {
        if (i == row - 1 && j == col - 1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int count = 0;
        for (int x = 0; x < 2; x++) {
            int nrow = i + delRow[x];
            int ncol = j + delCol[x];
            if (nrow < row && ncol < col && nrow >= 0 && ncol >= 0) {
                count += solve(row, col, nrow, ncol, delRow, delCol,dp);
            }
        }
        dp[i][j] = count;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        int delRow[] = {1, 0};
        int delCol[] = {0, 1};
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m, n, 0, 0, delRow, delCol,dp);
    }
};
