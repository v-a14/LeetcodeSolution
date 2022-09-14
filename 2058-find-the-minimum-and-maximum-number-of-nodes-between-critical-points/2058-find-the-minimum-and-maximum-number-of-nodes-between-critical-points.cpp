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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1, secondCritical = -1, lastCritical = -1;
        int ans = 1e9;
        int prevValue = head->val;
        head = head->next;
        int dis = 0;
        while(head){
            dis++;
            if(head->next){
                if((prevValue > head->val && head->next->val > head->val) || (prevValue < head->val && head->val > head->next->val)){
                    if(firstCritical == -1){
                        firstCritical = dis;
                        secondCritical = dis;
                    }else{
                        // cout << firstCritical << " " << secondCritical << " " << dis << endl;
                        ans = min(ans, dis - secondCritical);
                        secondCritical = dis;
                    }
                }
            }
            prevValue = head->val;
            head = head->next;
        }
        if(ans == 1e9) return {-1, -1};
        return {ans, secondCritical-firstCritical};
    }
};