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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=prev->next;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                int d=curr->val;
                while(curr && curr->val==d){
                       curr=curr->next;
                }
                prev->next=curr;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};