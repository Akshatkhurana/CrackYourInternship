class Solution {
public:
    vector<int> countZerOnes(string s) {
        int zero = 0;
        int one = 0;
        for(char c : s) {
            if(c == '0') zero++;
            else if(c == '1') one++;
        }
        return {zero, one};
    }

    int solve(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if(m == 0 && n == 0) {
            return 0;
        }
        if(i == strs.size()) {
            return 0;
        }
        if(dp[m][n][i] != -1) {
            return dp[m][n][i];
        }
        vector<int> count = countZerOnes(strs[i]);
        int zero = count[0];
        int one = count[1];
        int take = 0;
        if(m >= zero && n >= one) {
            take = 1 + solve(strs, m - zero, n - one, i + 1, dp);
        }
        int notTake = solve(strs, m, n, i + 1, dp);
        dp[m][n][i] = max(take, notTake);
        return dp[m][n][i];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size(), -1)));
        return solve(strs, m, n, 0, dp);
    }
};

