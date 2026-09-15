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
    ListNode* ReverseLinkedList(ListNode* head){
        if(head==NULL|| head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        ListNode* temp=head;
        while(temp!= NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //finding the middle;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newhead= ReverseLinkedList(slow->next);
        ListNode* first= head;
        ListNode* sec= newhead;
        while(sec){
            if(first->val!= sec->val){
                ReverseLinkedList(newhead);
                return false;
            }
            first=first->next;
            sec=sec->next;
        }
        ReverseLinkedList(newhead);
        return true;
    }
};