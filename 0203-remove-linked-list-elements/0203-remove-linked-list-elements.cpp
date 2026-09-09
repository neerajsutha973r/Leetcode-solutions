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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL ) return head;
        ListNode dummy;
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=prev->next;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode* next=curr->next;
                prev->next=next;
                curr=next;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return dummy.next;

    }
};