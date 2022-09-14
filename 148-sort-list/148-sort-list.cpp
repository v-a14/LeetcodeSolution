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
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(l1 && l2){
            if(l1->val > l2->val){
                temp->next = l2;
                l2 = l2->next;
            }else{
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummy->next;
    }
    ListNode *findMid(ListNode *head){
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid = findMid(head);
        ListNode *temp = mid->next;
        mid->next = NULL;
        return mergeList(sortList(head), sortList(temp));
    }
};