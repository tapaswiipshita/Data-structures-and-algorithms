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
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy,*fast=dummy;
        for(int i=1;i<left;i++){
            slow=slow->next;
        }
        for(int i=1;i<=right;i++){
            fast=fast->next;
        }
        ListNode* temp=fast->next;
        fast->next=NULL;
        ListNode* newnode=reverse(slow->next);
        slow->next=newnode;
        while(slow->next!=NULL){
            slow=slow->next;
        }
        slow->next=temp;
        return dummy->next;
    }
};