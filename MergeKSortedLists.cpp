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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        vector<int> temp;
        ListNode* curr = dummy;
        for(auto it:lists) {
            while(it != nullptr) {
                temp.push_back(it->val);
                it=it->next;
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++) {
            ListNode* n = new ListNode(temp[i]);
            curr -> next = n;
            curr = curr -> next;
        }
        return dummy->next;
    }
};
