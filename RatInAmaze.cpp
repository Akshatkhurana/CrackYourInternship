//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  string dir = "RLDU";
  int row[4] = {0,0,1,-1};
  int col[4] = {1,-1,0,0};
  vector<string> ans;
    void solve(vector<vector<int>> mat, int i,int j,string res,vector<vector<bool>> &vis) {
        if(i == mat.size()-1 && j == mat[0].size()-1) {
            ans.push_back(res);
            return;
        }
        for(int k=0;k<4;k++) {
            int nrow = i + row[k];
            int ncol = j + col[k];
            if(nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                vis[nrow][ncol] = 1;
                solve(mat,nrow,ncol,res + dir[k],vis);
                vis[nrow][ncol] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        string res = "";
        vector<vector<bool>> vis(mat.size(),vector<bool> (mat[0].size(),0));
        if(mat[0][0] == 1) {
            vis[0][0] = 1;
            solve(mat,0,0,res,vis);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
