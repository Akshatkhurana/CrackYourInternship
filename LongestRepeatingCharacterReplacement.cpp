class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        int maxlen = 0;
        unordered_map<char,int> mp;
        while(r < s.length()) {
            mp[s[r] - 'A']++;
            maxfreq = max(maxfreq,mp[s[r]-'A']);
            if((r-l+1) - maxfreq > k) {
                mp[s[l]-'A']--;
                l++;
                maxfreq = 0;
            }
            if(r-l+1 - maxfreq <= k) {
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
