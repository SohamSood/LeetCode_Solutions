//337
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
    // {a,b} a-> withroot , b-> withoutroot
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL) {
            return {0,0};
        }
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        int withoutroot = left.first + right.first;
        int withroot = left.second+right.second+root->val;
        return {max(withoutroot,withroot),withoutroot};
    }
    int rob(TreeNode* root) {
        pair<int,int> p = dfs(root);
        // cout<<p.first<<" "<<p.second<<endl;
        return max(p.first,p.second);
    }
};