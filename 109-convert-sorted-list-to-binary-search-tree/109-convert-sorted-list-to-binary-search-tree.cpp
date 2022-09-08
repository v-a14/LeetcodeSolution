/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *findMid(ListNode *head, ListNode *tail){
        ListNode *slow = head, *fast = head;
        while(fast!=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode *helper(ListNode *head, ListNode *tail){
        if(head == tail) return NULL;
        ListNode *mid = findMid(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        root->left = helper(head, mid);
        root->right = helper(mid->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *tail = NULL;
        return helper(head, tail);
    }
};