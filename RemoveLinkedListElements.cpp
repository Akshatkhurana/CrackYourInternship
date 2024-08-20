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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        if(head == nullptr)
        {
            return nullptr;
        }
        while(head != nullptr && head->val == val)
        {
            ListNode* todelete = head;
            head = head -> next;
            delete todelete;
        }
        ListNode* temp1 = head;
        while(temp1!=nullptr && temp1 -> next != nullptr)
        {
            if(temp1->next->val == val)
            {
                ListNode* todelete = temp1->next;
                temp1->next = temp1 -> next -> next;
                delete todelete;
                continue;
            }
            else
            temp1 = temp1 -> next;
        }
        return head;
    }
};
