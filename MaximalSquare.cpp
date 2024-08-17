class Solution {
public:
    int solve(vector<vector<char>>& matrix, int n,int m,int i, int j,int& maxi, vector<vector<int>> &dp) {
        if (i >= n || j >= m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = solve(matrix, n,m ,i, j + 1, maxi, dp);
        int down = solve(matrix, n, m, i + 1, j, maxi, dp);
        int diagonal = solve(matrix, n, m, i + 1, j + 1, maxi, dp);

        if (matrix[i][j] == '1') {
            dp[i][j] = min(right, min(down, diagonal)) + 1;
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        } else {
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int maxi = 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                solve(matrix, n,m, i, j, maxi, dp);
            }
        }

        return maxi * maxi;
    }
};

