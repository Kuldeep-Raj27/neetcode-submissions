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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;

        if (root == nullptr){
            s += 'N';
            return s;
        }

    queue<TreeNode*> q;
    q.push(root);

    // Loop until the queue becomes empty
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if(current==nullptr){
            s += "N#";
            continue;
        }

        // Process the current node
        s += to_string(current->val);
        s.push_back('#');

       
        q.push(current->left);
        q.push(current->right);       
    }
    s.pop_back();
    return s;
    }

    // Decodes your encoded data to tree.
   // Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.empty() || data == "N") return nullptr;

    // Use a stringstream to easily split the string by the '#' delimiter
    stringstream ss(data);
    string item;
    
    // Read the root value
    getline(ss, item, '#');
    if (item == "N") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // 1. Process the left child
        if (getline(ss, item, '#')) {
            if (item != "N") {
                current->left = new TreeNode(stoi(item));
                q.push(current->left);
            }
        }

        // 2. Process the right child
        if (getline(ss, item, '#')) {
            if (item != "N") {
                current->right = new TreeNode(stoi(item));
                q.push(current->right);
            }
        }
    }

    return root;
}

};
