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
        Node *curr = root;
        while(curr){
            Node *dummyNode = new Node(0);
            Node *dummyMove = dummyNode;
            while(curr){
                if(curr->left){
                    dummyMove->next = curr->left;
                    dummyMove = dummyMove->next;
                }
                if(curr->right){
                    dummyMove->next = curr->right;
                    dummyMove = dummyMove->next;
                }
                curr = curr->next;
            }
            curr = dummyNode->next;
        }
        return root;
    }
};