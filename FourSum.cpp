class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }
                long long tSum = (long long)target -
                                 ((long long)nums[i] + (long long)nums[j]);
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    long long currSum = (long long)nums[l] + (long long)nums[r];
                    if (currSum == tSum) {
                        vector<int> ans = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(ans);
                        while (l < r && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1]) {
                            r--;
                        }
                        l++;
                        r--;
                    } else if (currSum < tSum) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
