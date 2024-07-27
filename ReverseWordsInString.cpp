// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string token;
//         vector<string> temp;
//         while (getline(ss, token, ' ')) {
//             temp.push_back(token);
//         }
//         for (int i = 0; i < temp.size() / 2; i++) {
//             swap(temp[i], temp[temp.size() - i - 1]);
//         }
//         string res = "";
//         for (int i = 0; i < temp.size(); i++) {
//             if (i > 0) {
//                 res += " ";
//             }
//             res += temp[i];
//         }
//         return res;
//     }
// }; uper wale code me spaces ki dikkat aa rhi hai !!!!
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string> temp;

        while (ss >> token) {
            temp.push_back(token);
        }
        for (int i = 0; i < temp.size() / 2; i++) {
            swap(temp[i], temp[temp.size() - i - 1]);
        }
        string res = "";
        for (int i = 0; i < temp.size(); i++) {
            if (i > 0) {
                res += " ";
            }
            res += temp[i];
        }

        return res;
    }
};

