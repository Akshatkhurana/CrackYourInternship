class Solution {
public:
    int solve(string& s, int& n, int i, vector<int>& dp) {
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int curr = 0;
        curr += solve(s, n, i + 1, dp);
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
                curr += solve(s, n, i + 2, dp);
            }
        }
        dp[i] = curr;
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return solve(s, n, 0, dp);
    }
};
