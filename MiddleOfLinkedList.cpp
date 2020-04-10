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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* cur=head;
        while(cur){
            ++n;
            cur=cur->next;
        }
        //cout<<n<<endl;
        n=n/2;
        ++n;
        //cout<<n<<endl;
        cur=head;
        //cout<<cur->val<<endl;
        int count=1;
        while(count!=n){
            cur=cur->next;
            //cout<<cur->val<<endl;
            ++count;
        }
        return cur;
    }
};