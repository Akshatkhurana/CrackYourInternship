/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head)
    {
        int l =0;
        while(head!=nullptr)
        {
            head = head -> next;
            l++;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int diff = l1 - l2;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        if(diff > 0)
        {
            while(diff>0)
            {
                tempA = tempA -> next;
                diff--;
            }
        }
        else if(diff < 0)
        {
            while(diff<0)
            {
                tempB = tempB -> next;
                diff++;
            }
        }
        while(tempA != nullptr && tempB!= nullptr)
        {
            if(tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA -> next;
            tempB = tempB -> next;
        }
        return NULL;
    }
};
