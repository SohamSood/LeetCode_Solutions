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
    int count = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int left_max = dfs(root->left);
        int right_max = dfs(root->right);
        if(root->val >= max(left_max,right_max)) {
            count++;
        } 
        return max({root->val,left_max,right_max});
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};