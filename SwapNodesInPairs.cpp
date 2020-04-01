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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* cur, *prev, *temp;
        prev=head;
        temp=NULL;
        cur=head->next;
        head=head->next;
        //cout<<cur->val<<endl;
        while(cur->next){
            //cout<<cur->val<<" ";
            if(cur->next->next){
                prev->next=cur->next->next;
                temp=cur->next;
                cur->next=prev;
                prev=temp;
                if(temp->next)
                    cur=temp->next;
                else{ 
                    cur=NULL;
                    break;
                }
            }
            else{
                prev->next=cur->next;
                cur->next=prev;
                prev=prev->next;
                cur=NULL;
                break;
            }
        }
        //cout<<cur->val<<endl;
        if(cur)
            cur->next=prev;
        prev->next=NULL;
        return head;
    }
};