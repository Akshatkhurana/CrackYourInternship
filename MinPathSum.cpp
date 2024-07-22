class Solution {
public:
    int solve(vector<vector<int>> &grid,int delRow[],int delCol[],int i,int j, vector<vector<int>> &dp){
        int sum = INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        for(int x=0;x<2;x++) {
            int nrow = i + delRow[x];
            int ncol = j + delCol[x];
            if(nrow >=0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size()) {
                sum = min(sum,grid[i][j] + solve(grid,delRow,delCol,nrow,ncol,dp));
            }
        }
        dp[i][j] = sum;
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int delRow[] = {1,0};
        int delCol[] = {0,1};
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        int res = solve(grid,delRow,delCol,0,0,dp);
        return res;
    }
};
