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
    int getDecimalValue(ListNode* head) {
        string res ="";
        ListNode* temp = head;
        while(temp != nullptr) {
            res += to_string(temp->val);
            temp = temp->next;
        }
        reverse(res.begin(),res.end());
        cout<<res;
        int ans = 0;
        for(int i=0;i<res.length();i++) {
            ans += (res[i]-'0') * pow(2,i);
        }
        return ans;
    }
};
