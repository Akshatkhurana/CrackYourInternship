class Solution {
public:
    int solve(int idx,int buy,int n,vector<int>& prices,vector<vector<int>> &dp) {
        if(idx == n) {
            return 0;
        }
        if(dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        int profit = 0;
        if(buy) { 
            profit = max(-prices[idx]+solve(idx+1,0,n,prices,dp), 0 + solve(idx+1,1,n,prices,dp));
        }
        else {
            profit = max(prices[idx] + solve(idx+1,1,n,prices,dp), 0 + solve(idx+1,0,n,prices,dp));
        }
        dp[idx][buy] = profit;
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return solve(0,1,n,prices,dp);
    }
};
