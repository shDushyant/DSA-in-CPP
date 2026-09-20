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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // see the constraints hence used brute force of union of  two sorted arrays   
        /*vector<int>arr;
        while(l1 && l2){
             if(l1->val<=l2->val){
               arr.push_back(l1->val);
               l1=l1->next;
            }
            else{
                arr.push_back(l2->val);
                l2=l2->next;
            }
        }
        while(l2){
                    arr.push_back(l2->val);
                    l2=l2->next;
                }
        while(l1){
                    arr.push_back(l1->val);
                    l1=l1->next;
                }
            if(arr.empty()) return NULL;   // important case

        ListNode* head= new ListNode(arr[0]);
        ListNode* mover= head;
        for(int i=1;i<arr.size();i++){
            ListNode* temp= new ListNode(arr[i]);
            mover->next= temp;
            mover= mover->next;
        }
        return head;*/
        ListNode* dummy= new ListNode(-1);
        ListNode* res= dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                //ListNode* n= new ListNode(l1->val);
                res->next=l1;
                res= l1;
                l1=l1->next;
            }
            else{
               // ListNode* m= new ListNode(l2->val);
                res->next=l2;
                res=l2;
                l2=l2->next;
            }
        }
            if(l1){
                res->next=l1;
            }
            if(l2){
                res->next=l2;
            }
        return dummy->next;
    }
};