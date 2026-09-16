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
        vector<int>arr;
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
            if(arr.empty()) return NULL;

        ListNode* head= new ListNode(arr[0]);
        ListNode* mover= head;
        for(int i=1;i<arr.size();i++){
            ListNode* temp= new ListNode(arr[i]);
            mover->next= temp;
            mover= mover->next;
        }
        return head;
    }
};