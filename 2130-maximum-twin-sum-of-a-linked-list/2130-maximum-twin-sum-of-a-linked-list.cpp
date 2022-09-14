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
    ListNode *reverse(ListNode *head){
        ListNode *curr = head, *Next = NULL, *prev = NULL;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    int getLength(ListNode *root){
        int len = 0;
        while(root){
            len++;
            root = root->next;
        }
        return len;
    }
    int pairSum(ListNode* head) {
        int Len = getLength(head);
        int temp;
        if(Len%2 == 0){
            temp = Len/2 - 1;
        }else{
            temp = Len/2;
        }
        ListNode *curr = head;
        while(temp--){
            curr = curr->next;
        }
        curr->next = reverse(curr->next);
        ListNode *List1 = head, *List2 = curr->next;
        int sum = 0;
        while(List1 && List2){
            sum = max(List1->val + List2->val, sum);
            List1 = List1->next;
            List2 = List2->next;
        }
        return sum;
    }
};