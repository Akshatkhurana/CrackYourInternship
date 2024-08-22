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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        while(head != nullptr) {
            temp.push_back(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++) {
            ListNode* n = new ListNode(temp[i]);
            curr->next = n;
            curr = curr->next;
        }
        return dummy->next;
    }
};
