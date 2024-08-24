class Solution {
public:
    // int solve(vector<int> nums, int n, int idx) {
    //     int points = nums[idx];
    //     for(int i=0;i<n;i++) {
    //         if(i == idx) {
    //             continue;
    //         }
    //         else if(nums[i] == nums[idx] + 1) {
    //             nums.erase(nums.begin()+i,nums.begin()+i+1);
    //         }
    //         else if(nums[i] == nums[idx] - 1) {
    //             nums.erase(nums.begin()+i,nums.begin()+i+1);
    //         }
    //         else {
    //             points += nums[i];
    //         }
    //     }
    //     return points;
    // }
    // int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxi = 0;
    //     for(int i=0;i<n;i++) {
    //         int points=solve(nums,n,i);
    //         maxi = max(maxi,points);
    //     }
    //     return maxi;
    // }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> dp(maxi+1,0);
        vector<int> freq(maxi+1,0);
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
        }
        dp[1] = freq[1]*1;
        for(int i=2;i<=maxi;i++) {
            dp[i] = max(dp[i-1],dp[i-2] + freq[i]*i);
        }
        return dp[maxi];
    }
};
