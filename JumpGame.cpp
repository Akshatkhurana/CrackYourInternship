class Solution {
public:
    bool solve(vector<int>& nums, int n, int i, vector<int>& dp) {
        if (i >= n - 1) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        for (int j = 1; j <= nums[i]; j++) {
            if (solve(nums, n, i + j, dp)) {
                return dp[i] = true; 
            }
        }
        return dp[i] = false; 
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n, 0, dp);
    }



    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1)
    //     return true;
    //     int final = n-1;
    //     for(int i=n-1 ; i>=0 ; i--)
    //     {
    //         if(i + nums[i] >= final)
    //         {
    //             final = i;
    //         }
    //     }
    //     if(final == 0)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    // Both are correct
};

