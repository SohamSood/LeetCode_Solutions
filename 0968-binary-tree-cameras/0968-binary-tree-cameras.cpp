//968
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
    const int no = 1e9;
    vector<int> dfs(TreeNode* root) {
        if(root == NULL) return {no,0,0};
        vector<int> lefty = dfs(root->left);
        vector<int> righty = dfs(root->right);
        int have = 1 + min({lefty[0],lefty[1],lefty[2]}) + min({righty[0],righty[1],righty[2]});
        int covered = min(lefty[0]+min(righty[0],righty[1]),righty[0]+min(lefty[0],lefty[1]));
        int nothing = lefty[1]+righty[1];
        return {have,covered,nothing};
    }
    int minCameraCover(TreeNode* root) {
        auto p = dfs(root);
        // i have the camera
        // i dont have the camera but m covered 
        // i dont have the camera neither m covered 
        return min(p[0],p[1]);
    }
};