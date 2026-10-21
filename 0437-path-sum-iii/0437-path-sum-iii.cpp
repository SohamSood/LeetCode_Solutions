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
    void preorder(TreeNode* root,vector<long long>& myarr,unordered_map<long long,long long>& freq,int target) {
        if(root==NULL) return;
        if(myarr.size() == 0) myarr.push_back(root->val);
        else myarr.push_back(myarr.back()+root->val);
        if(freq.find(myarr.back() - target) != freq.end()) {
            count+=freq[myarr.back() - target];
        } 
        freq[myarr.back()]++;
        preorder(root->left,myarr,freq,target);
        preorder(root->right,myarr,freq,target);
        if(freq[myarr.back()] == 1) freq.erase(myarr.back());
        else freq[myarr.back()]--;
        myarr.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> myarr;
        unordered_map<long long,long long> freq;
        freq[0] = 1;
        preorder(root,myarr,freq,targetSum);
        return count;
    }   
};