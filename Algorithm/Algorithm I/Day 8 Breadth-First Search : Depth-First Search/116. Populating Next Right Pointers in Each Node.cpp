/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        
        vector<Node*> vec;
        vec.push_back(root);
        while (!vec.empty()) {
            vector<Node*> nxt;
            for (int i = 0; i < vec.size(); i++) {
                Node* node = vec[i];
                if (node->left)
                    nxt.push_back(node->left);
                if (node->right)
                    nxt.push_back(node->right);
                node->next = i != vec.size() - 1 ? vec[i + 1] : NULL;
            }
            vec = nxt;
        }
        return root;
    }
};