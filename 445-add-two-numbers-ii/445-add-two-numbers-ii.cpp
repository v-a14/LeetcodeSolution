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
class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *curr = head, *prev = NULL, *Next = NULL;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *dummyNode = new ListNode(0);
        ListNode *head = dummyNode;
        int carry = 0;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            carry = val/10;
            val = val%10;
            head->next = new ListNode(val);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int val = l1->val + carry;
            carry = val/10;
            val = val%10;
            head->next = new ListNode(val);
            head = head->next;
            l1 = l1->next;
        }
        while(l2){
            int val = l2->val + carry;
            carry = val/10;
            val = val%10;
            head->next = new ListNode(val);
            head = head->next;
            l2 = l2->next;
        }
        if(carry){
            head->next = new ListNode(carry);
        }
        return reverseList(dummyNode->next);
        return dummyNode->next;
    }
};