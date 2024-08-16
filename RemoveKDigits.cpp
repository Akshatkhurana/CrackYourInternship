class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char> st;
        if(k > num.length())
        {
            return "0";
        }
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k > 0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            if(!st.empty() || num[i]!=0)
            {
                st.push(num[i]);
            }
        }
        while(!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        if(st.empty())
        {
            return "0";
        }
        while(!st.empty())
        {
            num[n-1]=st.top();
            st.pop();
            n--;
        }
        string res = num.substr(n);
        while(res.front()=='0' && res.length()!=1)
        {
            res.erase(res.begin());
        }
        return res;
    }
};
