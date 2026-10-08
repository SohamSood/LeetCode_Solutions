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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> isRoot;
        for(int i = 0;i<descriptions.size();i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            if(mp.find(parent)==mp.end()) {
                TreeNode* p = new TreeNode(parent);
                mp[parent] = p;
                isRoot[parent] = true;
            }
            if(mp.find(child)==mp.end()) {
                TreeNode* c = new TreeNode(child);
                mp[child] = c;
            }
            isRoot[child] = false;
            if(descriptions[i][2] == 1) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
        }   
        for(auto& p:isRoot) {
            if(p.second == true) {
                return mp[p.first];
            }
        }
        return NULL;
    }
};