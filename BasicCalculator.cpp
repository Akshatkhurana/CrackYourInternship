class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        string res = s; // Initialize res with the original string
        
        for (int i = 0; i < n; i++) {
            int a = 1;
            int b = 1;
            if (s[i] == '/') {
                while (i - a >= 0 && s[i - a] == ' ') {
                    a++;
                }
                while (i + b < n && s[i + b] == ' ') {
                    b++;
                }
                int ch1 = s[i - a] - '0';
                int ch2 = s[i + b] - '0';
                int ans = ch1 / ch2;
                string temp = to_string(ans);
                string start = res.substr(0, i - a);
                string end = res.substr(i + b + 1, n - (i + b + 1));
                res = start + temp + end;
                s = res;
                n = s.length();
                i = -1; // Reset loop to handle new string
            }
        }

        for (int i = 0; i < n; i++) {
            int a = 1;
            int b = 1;
            if (s[i] == '*') {
                while (i - a >= 0 && s[i - a] == ' ') {
                    a++;
                }
                while (i + b < n && s[i + b] == ' ') {
                    b++;
                }
                int ch1 = s[i - a] - '0';
                int ch2 = s[i + b] - '0';
                int ans = ch1 * ch2;
                string temp = to_string(ans);
                string start = res.substr(0, i - a);
                string end = res.substr(i + b + 1, n - (i + b + 1));
                res = start + temp + end;
                s = res;
                n = s.length();
                i = -1; // Reset loop to handle new string
            }
        }

        for (int i = 0; i < n; i++) {
            int a = 1;
            int b = 1;
            if (s[i] == '+') {
                while (i - a >= 0 && s[i - a] == ' ') {
                    a++;
                }
                while (i + b < n && s[i + b] == ' ') {
                    b++;
                }
                int ch1 = s[i - a] - '0';
                int ch2 = s[i + b] - '0';
                int ans = ch1 + ch2;
                string temp = to_string(ans);
                string start = res.substr(0, i - a);
                string end = res.substr(i + b + 1, n - (i + b + 1));
                res = start + temp + end;
                s = res;
                n = s.length();
                i = -1; // Reset loop to handle new string
            }
        }

        for (int i = 0; i < n; i++) {
            int a = 1;
            int b = 1;
            if (s[i] == '-') {
                while (i - a >= 0 && s[i - a] == ' ') {
                    a++;
                }
                while (i + b < n && s[i + b] == ' ') {
                    b++;
                }
                int ch1 = s[i - a] - '0';
                int ch2 = s[i + b] - '0';
                int ans = ch1 - ch2;
                string temp = to_string(ans);
                string start = res.substr(0, i - a);
                string end = res.substr(i + b + 1, n - (i + b + 1));
                res = start + temp + end;
                s = res;
                n = s.length();
                i = -1; // Reset loop to handle new string
            }
        }
        return stoi(res);
    }
};

