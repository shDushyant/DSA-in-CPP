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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp= head;
        vector<int>arr;
        while(temp){
           arr.push_back(temp->val);
           temp=temp->next;
        }
        int i= left-1;
        int j=right-1;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        ListNode* head1= new ListNode(arr[0]);
        ListNode* mover= head1;
        for(int i=1;i<arr.size();i++){
            ListNode* temp=new ListNode(arr[i]);
            mover->next= temp;
            mover=temp;
        }
         return head1;
        
    }
};