class Solution {
public:
    bool check(string s,int i,int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return check(s,l+1,r) || check(s,l,r-1);
            }
        }
        return true;
    }
};
