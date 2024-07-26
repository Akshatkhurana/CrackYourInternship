//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(unordered_map<int,vector<int>> &mp, vector<int> &res, vector<bool> &vis,int u) {
        queue<int> q;
        q.push(u);
        vis[u] = true;
        res.push_back(u);
        while(!q.empty()) {
            int st = q.front();
            q.pop();
            for(auto it: mp[st]) {
                if(!vis[it]) {
                    q.push(it);
                    res.push_back(it);
                    vis[it] = true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<V;i++) {
            for(auto it=adj[i].begin();it!=adj[i].end();it++) {
                mp[i].push_back(*it);
            }
        }
        vector<bool> vis(V,false);
        vector<int> res;
        bfs(mp,res,vis,0);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
