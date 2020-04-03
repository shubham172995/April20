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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=n;
        ListNode* cur=head;
        while(l){
            --l;
            cur=cur->next;
        }
        if(cur==NULL){
            head=head->next;
            return head;
        }
        ListNode* prev=head;
        while(cur->next){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};