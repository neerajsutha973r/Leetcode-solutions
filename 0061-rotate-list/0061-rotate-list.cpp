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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int n=1;
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            n++;
    
        }
        k%=n;
        if(k==0) return head;
        curr->next=head;
        ListNode* prev=head;
        int steps=n-k-1;
        while(steps--){
             prev=prev->next;
        }
        ListNode* newlist=prev->next;
        prev->next=NULL;
        return newlist;
    }
};