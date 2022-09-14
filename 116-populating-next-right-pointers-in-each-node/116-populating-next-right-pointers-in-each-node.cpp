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
            Node *dummy = new Node(0);
            Node *temp = dummy;
            while(curr){
                if(curr->left){
                    dummy->next = curr->left;
                    dummy = dummy->next;
                }
                if(curr->right){
                    dummy->next = curr->right;
                    dummy = dummy->next;
                }
                curr = curr->next;
            }
            curr = temp->next;
        }
        return root;
    }
};