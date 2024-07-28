class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(auto it:strs) {
            string temp = it;
            sort(it.begin(),it.end());
            mp[it].push_back(temp);
        }
        for(auto it: mp) {
            vector<string> temp=it.second;
            result.push_back(temp);
        }
        return result;
    }
};
