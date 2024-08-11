class Solution {
public:
    string reverse(string res) {
        for(int i=0;i<res.length()/2;i++) {
            swap(res[i],res[res.length()-1-i]);
        }
        return res;
    }
    string convertToTitle(int columnNumber) {
        unordered_map<int,char> mp;
        for(int i=1;i<=26;i++) {
            mp[i] = 'A' + i-1;
        }
        string res="";
        while(columnNumber > 0) {
            int rem = columnNumber % 26;
            if(rem == 0) {
                res += 'Z';
                columnNumber -= 1;
            }
            else {
                res += mp[rem];
            }
            columnNumber /= 26;
        }
        res = reverse(res);
        return res;
    }
};
