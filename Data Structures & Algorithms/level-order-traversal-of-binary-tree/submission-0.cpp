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
//    /////////////////////////////////////
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
// ////////////////////////////
    void printCurrentLevel(vector<int>& r,TreeNode* root, int level) {
    if (root == nullptr) return;
    
    // Base case: if we reached the desired level, print the node
    if (level == 1) {
        // std::cout << root->data << " ";
        r.push_back(root->val);
    } 
    // If level is greater than 1, move down to the next level
    else if (level > 1) {
        printCurrentLevel(r,root->left, level - 1);
        printCurrentLevel(r, root->right, level - 1);
    }
    
}
// //////////////////////

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int height =getHeight(root);
        for(int i=1;i<=height;i++){
            vector<int> r={};
            printCurrentLevel(r,root,i);
            ans.push_back(r);
        }
        return ans;
    }
};
