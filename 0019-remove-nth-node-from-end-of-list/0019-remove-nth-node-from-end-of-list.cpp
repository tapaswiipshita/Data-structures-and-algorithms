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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==1) return NULL;
        int index=count-n;
        if(index==0){
            head=head->next;
            return head;
        }
        temp=head;
        ListNode *prev=NULL;
        while(index){
            prev=temp;
            temp=temp->next;
            index--;
        }
        if(temp->next==NULL) prev->next=NULL;
        else{
            prev->next=temp->next;
        }
        return head;
    }
};