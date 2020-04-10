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
        map<int, bool> m, n;
        if(!head||!(head->next))
            return head;
        m[head->val]=1;
        ListNode* cur=head->next;
        ListNode* prev=head;
        while(cur){
            if(m[cur->val]){
                n[cur->val]=1;
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                m[cur->val]=1;
                cur=cur->next;
                prev=prev->next;
            }
        }
        if(!head->next){
            if(n[head->val])
                head=NULL;
            return head;
        }
        cur=head->next;
        prev=head;
        while(cur){
            if(n[cur->val]){
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                prev=prev->next;
                cur=cur->next;
            }
        }
        while(head){
            if(n[head->val])
                head=head->next;
            else break;
        }
        return head;
    }
};