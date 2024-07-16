//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int row,int col) {
        queue<pair<int,int>> q;
        vis[row][col] = 1;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int delr=-1;delr <= 1;delr++) {
                for(int delc = -1;delc<=1;delc++) {
                    int nrow = r + delr;
                    int ncol = c + delc;
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m 
                    && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
