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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=nullptr;
        ListNode* curr=nullptr;
        int carry=0;
        while(l1 != nullptr || l2!=nullptr || carry>0)
        {
            if(l1!=nullptr)
            {
                carry=carry + l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr)
            {
                carry=carry+l2->val;
                l2=l2->next;
            }
            int digit=carry%10;
            carry=carry/10;
            if (res == nullptr) {
                res = new ListNode(digit);
                curr = res;
            } else {
                curr->next = new ListNode(digit);
                curr = curr->next;
            }
        }
        return res;
    }
};
