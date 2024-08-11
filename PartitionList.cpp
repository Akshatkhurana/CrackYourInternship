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
    ListNode* partition(ListNode* head, int x) {
        vector<int> store;
        ListNode* temp = head;
        int n = store.size();
        vector<int> small;
        vector<int> large;
        while(temp != nullptr) {
           if(temp->val < x) {
            small.push_back(temp->val);
           }
           else {
            large.push_back(temp->val);
           }
           temp = temp -> next;
        }
        ListNode* temp1 = head;
        for(int i=0;i<small.size();i++) {
            temp1->val = small[i];
            temp1 = temp1 -> next;
        }
        for(int i=0;i<large.size();i++) {
            temp1->val = large[i];
            temp1 = temp1 -> next;
        }
        return head;
    }
};
