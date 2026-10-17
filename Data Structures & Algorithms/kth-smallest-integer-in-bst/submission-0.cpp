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
    int counter=0;
    int ans=0;
    void meow(TreeNode* root, int k){
         if(root==nullptr) return;
        meow(root->left, k);
        counter++;
        if(counter==k) ans=root->val;
        meow(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        meow(root, k);
        return ans;       

    }
};
