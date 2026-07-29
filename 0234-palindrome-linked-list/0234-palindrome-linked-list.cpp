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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        //find middle of ll
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the 2nd half
        ListNode* prev = NULL;
        while(slow!=NULL){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        //comparing both halves
        while(prev!=NULL){
            if(head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};