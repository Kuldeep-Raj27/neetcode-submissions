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
    bool scanTree(TreeNode* child, TreeNode* p, TreeNode*q){
        if(child==nullptr) return false;
        if(child==p || child==q){
            return true;
        }
        return scanTree(child->left,p,q) || scanTree(child->right,p,q);
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return nullptr;
        }
        if(root==p || root==q){ return root;}
        bool a = scanTree(root->left,p,q);
        bool b = scanTree(root->right,p,q); // return true if p or q is there. 
        if(a && b){ 
            return root;
        }
        if(a){
            return lowestCommonAncestor(root->left,p,q);
        }
        return lowestCommonAncestor(root->right,p,q);
    
        
    }
};
