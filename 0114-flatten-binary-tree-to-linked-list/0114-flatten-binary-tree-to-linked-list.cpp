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
    void preorder(TreeNode* temp,vector<TreeNode*>& myarr) {
        if(temp == NULL) return;
        myarr.push_back(temp);
        preorder(temp->left,myarr);
        preorder(temp->right,myarr);
    } 
    void flatten(TreeNode* root) {
        if(root == NULL) return; 
        vector<TreeNode*> myarr;
        preorder(root,myarr);
        for(int i = 0;i<myarr.size()-1;i++) {
            myarr[i]->right = myarr[i+1];
            myarr[i]->left = NULL;
        }
    }
};