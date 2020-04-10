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
    ListNode* deleteDuplicates(ListNode* head) {
        //map<int, bool> m;
        if(!head||!(head->next))
            return head;
        //m[head->val]=1;
        ListNode* cur=head->next;
        ListNode* prev=head;
        while(cur){
            if(cur->val==prev->val){
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                cur=cur->next;
                prev=prev->next;
            }
        }
        return head;
    }
};