class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int n = s.length();
        int count = t.length();
        int i = 0;
        int j = 0;
        int winSize = INT_MAX;
        int startidx = -1;
        while (j < n) {
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;
            while (count == 0) {
                int currSize = j - i + 1;
                if (winSize > currSize) {
                    winSize = currSize;
                    startidx = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }
        return winSize == INT_MAX ? "" : s.substr(startidx, winSize);
    }
};
