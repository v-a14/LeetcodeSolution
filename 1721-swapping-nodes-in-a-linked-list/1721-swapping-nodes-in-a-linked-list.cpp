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
    int getLen(ListNode *head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLen(head);
        if(k>len) return head;
        if(k == len-k+1)  return head;
        int val = len - k + 1;
        if(val < k) swap(val, k);
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *start = dummyNode, *prevStart;
        ListNode *end = dummyNode, *prevEnd;
        while(k--){
            prevStart = start;
            start = start->next;
        }
        while(val--){
            prevEnd = end;
            end = end->next;
        }
        if(start->next == end){
            prevStart->next = end;
            ListNode *temp = end->next;
            end->next = start;
            start->next = temp;
        }else{
            ListNode *temp = end->next;
            end->next = start->next;
            prevEnd->next = start;
            start->next = temp;
            prevStart->next = end;
        }
        return dummyNode->next;
    }
};