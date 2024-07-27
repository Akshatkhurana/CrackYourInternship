class Solution {
public:
    void solve(int n,int oc,int cc,vector<string> &ans,string res) {
        if(oc == n && cc == n) {
            ans.push_back(res);
        }
        if(oc < n) {
            solve(n,oc+1,cc,ans,res+"(");
        }
        if(cc < oc) {
            solve(n,oc,cc+1,ans,res+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0;
        int cc = 0;
        solve(n,oc,cc,ans,"");
        return ans;
    }
};
