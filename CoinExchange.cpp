class Solution {
public:
    int solve(vector<int>& coins, int amt, vector<int>& dp) {
        if (amt == 0) {
            return 0;
        }
        if (amt < 0) {
            return INT_MAX;
        }
        if (dp[amt] != -1) {
            return dp[amt];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amt - coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        dp[amt] = mini;
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = solve(coins, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};

