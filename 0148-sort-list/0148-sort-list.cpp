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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                ListNode* temp=new ListNode(l1->val);
                curr->next=temp;
                curr=curr->next;
                l1=l1->next;
            }
            else{
                ListNode* temp=new ListNode(l2->val);
                curr->next=temp;
                curr=curr->next;
                l2=l2->next;
            }
        }
        while(l1){
            ListNode* temp=new ListNode(l1->val);
            curr->next=temp;
            curr=curr->next;
            l1=l1->next;
        }
        while(l2){
            ListNode* temp=new ListNode(l2->val);
            curr->next=temp;
            curr=curr->next;
            l2=l2->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* slow=head, *fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(temp);
        return merge(l1,l2);
    }
};