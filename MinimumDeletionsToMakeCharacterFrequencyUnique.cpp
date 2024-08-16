class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        vector<int> temp;
        for (auto it : mp) {
            temp.push_back(it.second);
        }
        int count = 0;
        sort(temp.begin(), temp.end(), [](const auto a,const auto b) {
            return a>b;
        });
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << endl;
        }
        for (int i = 1; i < temp.size(); i++) {
            while (temp[i] > 0 && temp[i] >= temp[i - 1]) {
                temp[i]--;
                count++;
            }
        }
        return count;
    }
};
