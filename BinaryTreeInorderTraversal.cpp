/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> solve(TreeNode* root, vector<int> &temp) {
        if(root != NULL) {
            solve(root->left,temp);
            temp.push_back(root->val);
            solve(root->right,temp);
        }
        return temp;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;
        return solve(root,temp);
    }
};
