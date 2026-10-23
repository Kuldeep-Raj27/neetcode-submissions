/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        unordered_map<int, Node*> cache;

        if(!node){
            return nullptr;
        }
        q.push(node);
        Node* p2 = new Node(node->val);
        cache[p2->val] = p2;

        while(!q.empty()){
            Node* graph1 = q.front();
            q.pop();
            Node* graph2 = nullptr;
            graph2 = cache[graph1->val];

            for(auto ptr:graph1->neighbors){
                Node* temp=nullptr;
                if(!cache.contains(ptr->val)){
                    q.push(ptr);
                    temp = new Node(ptr->val);
                    cache[temp->val] = temp;
                }
                else{
                    temp = cache[ptr->val];
                }
                graph2->neighbors.push_back(temp);
            }
           
           
        }
        return p2;
    }
};
