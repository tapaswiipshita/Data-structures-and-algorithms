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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* first=head,*second=head->next;
        while(second!=NULL){
            int GCD=__gcd(first->val,second->val); 
            ListNode* temp=new ListNode(GCD);
            temp->next=first->next;
            first->next=temp;
            first=second;
            second=second->next;
        }
        return head;
    }
};