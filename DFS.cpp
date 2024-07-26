//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(unordered_map<int,vector<int>>& mp,vector<bool> &vis,vector<int> &res,int u) {
        if(vis[u] == true) {
            return;
        }
        vis[u] = true;
        res.push_back(u);
        for(auto it:mp[u]) {
            if(!vis[it]) {
                dfs(mp,vis,res,it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<V;i++) {
            for(auto j=adj[i].begin();j!=adj[i].end();j++) {
                mp[i].push_back(*j);
            }
        }
        vector<bool> vis(V,false);
        vector<int> res;
        dfs(mp,vis,res,0);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
