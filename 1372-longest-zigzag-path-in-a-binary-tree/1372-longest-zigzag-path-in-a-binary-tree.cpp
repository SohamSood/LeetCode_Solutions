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
    int ans = 0;
    //<left tree,right tree>
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL) {
            return {-1,-1};
        }
        pair<int,int> lefty = dfs(root->left);
        pair<int,int> righty = dfs(root->right);
        ans = max(ans,lefty.first+1);
        ans = max(ans,lefty.second);
        ans = max(ans,righty.first);
        ans = max(ans,righty.second+1);
        return {righty.second+1,lefty.first+1};
    }
    int longestZigZag(TreeNode* root) {
        auto p = dfs(root);
        ans = max(ans,p.first);
        ans = max(ans,p.second);
        return ans;
    }
};