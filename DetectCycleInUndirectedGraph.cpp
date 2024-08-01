class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            string temp = details[i];
            int j = 0;
            string res = "";
            while(j < temp.size()-2) {
                j = 11;
                res += temp[j];
                j++;
            }
            int age = stoi(res);
            if(age > 60) {
                count++;
            }
        }
        return count;
    }
};
