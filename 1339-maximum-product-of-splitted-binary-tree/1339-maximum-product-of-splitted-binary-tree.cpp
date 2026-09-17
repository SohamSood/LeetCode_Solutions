/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int sum_of_tree;
    int mod = 1e9+7;
    long long currMax;
    int sum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int total_sum = root->val + dfs(root->left)+dfs(root->right);
        long long product = 1LL * total_sum * (sum_of_tree - total_sum);
        currMax = max(currMax, product);
        return total_sum;
    }
    int maxProduct(TreeNode* root) { 
        sum_of_tree = sum(root);
        currMax = INT_MIN;
        int a = dfs(root);
        return currMax%mod;
    }
};