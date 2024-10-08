//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>> &mat,vector<vector<int>> &vis, int row, int col,int delrow[],int delcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && 
            ncol < m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(mat,vis,nrow,ncol,delrow,delcol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int> (m,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int j=0;j<m;j++) {
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(mat,vis,0,j,delrow,delcol);
            }
            if(!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(mat,vis,n-1,j,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++) {
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(mat,vis,i,0,delrow,delcol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(mat,vis,i,m-1,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } 
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
