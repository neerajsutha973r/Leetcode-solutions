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
        ListNode*temp=head;
        int c=0;
        while(temp){
           c++;
           temp=temp->next;
        }
        ListNode* prev=head;
         if(c == n){
            return head->next;
        }

        for(int i=1;i<c-n;i++){
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;
        
    }
};