class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> adj = {
        {4, 6},    // 0
        {6, 8},    // 1
        {7, 9},    // 2
        {4, 8},    // 3
        {3, 9, 0}, // 4
        {},        // 5
        {1, 7, 0}, // 6
        {2, 6},    // 7
        {1, 3},    // 8
        {2, 4}     // 9
    };
    int solve(int n, int i, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][i] != -1) {
            return dp[n][i];
        }
        int ans = 0;
        for (int& nextidx : adj[i]) {
            ans = (ans + solve(n - 1, nextidx, dp)) % M;
        }
        dp[n][i] = ans;
        return dp[n][i];
    }
    int knightDialer(int n) {
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        for (int i = 0; i <= 9; i++) {
            res = (res + solve(n - 1, i, dp)) % M;
        }
        return res;
    }
};
