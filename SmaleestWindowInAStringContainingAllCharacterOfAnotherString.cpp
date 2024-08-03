//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow(string s, string p) {
        unordered_map<char, int> mp;
        for (char c : p) {
            mp[c]++;
        }
        
        int n = s.length();
        int count = p.length();
        int i=0;
        int j = 0;
        int winSize = INT_MAX;
        int startidx = -1;
        while(j < n) {
            if(mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;
            while(count == 0) {
                int currSize = j-i+1;
                if(winSize > currSize) {
                    winSize = currSize;
                    startidx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }
        return winSize == INT_MAX ? "-1": s.substr(startidx,winSize);
    }
};



//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
