/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        if (!ans.count(node)) {
            ans[node] = new Node(node->val, {});
            for (Node* neighbor : node->neighbors)
                ans[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        return ans[node];
    }

private:
    unordered_map<Node*, Node*> ans;
};