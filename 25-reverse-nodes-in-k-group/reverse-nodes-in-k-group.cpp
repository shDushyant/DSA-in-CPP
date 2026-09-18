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
   /* ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* front= NULL;
        while(temp){
            temp->next=front;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }*/
    ListNode* reverseKGroup(ListNode* head, int k) {
       vector<int>arr;
       ListNode* temp=head;
       while(temp){
        arr.push_back(temp->val);
        temp=temp->next;
       }
       for(int i=0;i<arr.size();i++){
        if((i+1)%k==0){
            int l=(i+1)-k;
            int r=i;
            while(l<=r){
                swap(arr[l],arr[r]);
                l++;
                r--;
            }
        }
       }
       int i=0;
       temp=head;
       while(temp){
        temp->val=arr[i];
        i++;
        temp=temp->next;
       }
       return head;
    }
};