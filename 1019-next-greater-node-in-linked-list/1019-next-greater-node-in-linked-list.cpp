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
        ListNode *curr = head, *prev = NULL, *Next;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>st;
        vector<int>ans;
        head = reverseList(head);
        while(head){
            while(!st.empty() && st.top()<=head->val){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(st.top());
            }
            st.push(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};