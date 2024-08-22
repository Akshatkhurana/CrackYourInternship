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
    void swapNum(int i,int j,vector<int> &temp) {
        while(i <= j) {
            swap(temp[i],temp[j]);
            i++;
            j--;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> store;
        while(temp != nullptr) {
            store.push_back(temp->val);
            temp = temp->next;
        }
        int i=0,j=0;
        int n = store.size();
        while(j < n && i < n) {
            if(j - i + 1 == k) {
                swapNum(i,j,store);
                i=j+1;
            }
            else {
                j++;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i=0;i<store.size();i++) {
            ListNode* n = new ListNode(store[i]);
            curr->next = n;
            curr = curr->next;
        }
        return dummy->next;
    }
};
