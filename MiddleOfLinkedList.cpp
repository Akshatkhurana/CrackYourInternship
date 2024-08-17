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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        if(head -> next == nullptr) {
            return head;
        }
        int len = 0;
        while(temp1 != nullptr) {
            len++;
            temp1 = temp1->next;
        }
        int i=0;
        while(i < len/2-1) {
            temp2 = temp2->next;
            i++;
        }
        return temp2->next;
    }
};
