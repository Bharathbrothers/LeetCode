/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;

        while (node && node->left) {
            Node* next = node->left;
            while (node) {
                node->left->next = node->right;
                node->right->next = node->next ? node->next->left : NULL;
                node = node->next;
            }
            node = next;
        }

        return root;
    }
};