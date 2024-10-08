//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        stack<int> st;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(isdigit(s[i])) {
                st.push(s[i]-'0');
            }
            else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                if(s[i] == '+') {
                    st.push(val1 + val2);
                }
                if(s[i] == '-') {
                    st.push(val2 - val1);
                }
                if(s[i] == '*') {
                    st.push(val1 * val2);
                }
                if(s[i] == '/') {
                    st.push(val2 / val1);
                }
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
