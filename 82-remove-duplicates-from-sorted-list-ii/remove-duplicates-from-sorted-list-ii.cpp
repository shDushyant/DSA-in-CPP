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
        if((head==NULL)|| head->next==NULL) return head;
        ListNode* temp=head;
        unordered_map<int ,int>mpp;
        while(temp){
          mpp[temp->val]++;
          temp=temp->next;
        }
        if(mpp.empty()) return NULL;
        ListNode* dummy=new ListNode(-1);
        ListNode* mover= dummy;
        temp=head;
        while(temp){
            if(mpp[temp->val]==1){
                ListNode* temp2= new ListNode(temp->val);
                mover->next= temp2;
                mover=temp2;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};