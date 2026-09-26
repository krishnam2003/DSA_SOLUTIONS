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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        if (n == cnt) {
            ListNode* ans = head;
            head = head->next;
            delete ans;
            return head;
        }

        int count = cnt-n;
        ListNode* tmp = head;
        while(count > 1){
            tmp = tmp->next;
            count--;
        }

        ListNode* ans = tmp->next;
        tmp->next = tmp->next->next;

        delete ans;

        return head;
    }
};