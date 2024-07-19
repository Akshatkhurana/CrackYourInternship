class Solution {
public:
    int countOnes(int num) {
        int count = 0;
        while(num > 0) {
            int rem = num % 2;
            cout<<rem<<endl;
            if(rem == 1) {
                count++;
            }
            num = num / 2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n == 0) {
            ans.push_back(0);
        }
        for(int i=0;i<=n;i++) {
            ans[i] = countOnes(i);
        }
        return ans;
    }
};
