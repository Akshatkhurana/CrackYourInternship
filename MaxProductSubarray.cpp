class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxProd = INT_MIN;
        int n = nums.size();
        double pref = 1;
        double suff = 1;
        if(n == 0) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            if(pref == 0) {
                pref = 1;
            }
            if(suff == 0) {
                suff = 1;
            }
            pref = pref * nums[i];
            suff = suff * nums[n-i-1];

            maxProd = max(maxProd,max(pref,suff));
        }
        return (int)maxProd;
    }
};
