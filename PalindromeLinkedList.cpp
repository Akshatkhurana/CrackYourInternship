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
        vector<int> s1;
        ListNode* temp1 = head;
        while(temp1 != nullptr)
        {
            s1.push_back(temp1 -> val);
            temp1 = temp1 -> next;
        }
        for(int i=0 ; i < s1.size() ; i++)
        {
            if(s1[i] != s1[s1.size() - i -1])
            return false;
        }
        return true;
    }
};
