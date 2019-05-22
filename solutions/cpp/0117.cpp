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
        Node* curr = new Node(NULL);
        Node* prev = curr;

        while (node) {
            while (node) {
                curr->next = node->left;
                if (curr->next) curr = curr->next;
                curr->next = node->right;
                if (curr->next) curr = curr->next;
                node = node->next;
            }
            node = prev->next;
            curr = prev;
        }

        return root;
    }
};