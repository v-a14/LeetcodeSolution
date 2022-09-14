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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int>s;
        for(auto it:nums) s.insert(it);
        int count = 0;
        ListNode *curr = head;
        while(curr){
            int val = curr->val;
            if(s.find(val) != s.end()){
                while(curr && s.find(curr->val)!=s.end()){
                    curr = curr->next;
                }
                count++;
            }else{
                curr = curr->next;
            }
        }
        return count;
    }
};