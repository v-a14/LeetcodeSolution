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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *first = head, *second = head->next, *tempSecond = head->next;
        bool flag = true;
        ListNode *prev;
        while(first && second){
            if(flag){
                prev = first;
                first->next = second->next;
                first = first->next;
                flag = !flag;
            }else{
                second->next = first->next;
                second = second->next;
                flag = !flag;
            }
        }
        if(!first)
            prev->next = tempSecond;
        else first->next = tempSecond;
        return head;
    }
};