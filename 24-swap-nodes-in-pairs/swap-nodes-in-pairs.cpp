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
    ListNode* findPair(ListNode* temp,int k){
        k--;
        while(temp && k>0){
          k--;
          temp=temp->next;
        }
        return temp;
    }
    ListNode* Reverse(ListNode* head1){
        ListNode* prev=NULL;
        ListNode* curr=head1;
        ListNode* front=NULL;
        while(curr){
            front= curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        /*ListNode* temp= head;
        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i<arr.size();i++){
            if((i+1)%2==0) swap(arr[i-1],arr[i]);
        }
        ListNode* head1= new ListNode(arr[0]);
        ListNode* mover= head1;
        for(int i=1;i<arr.size();i++){
            ListNode* temp2=new ListNode(arr[i]);
            mover->next=temp2;
            mover= mover->next;
        }

        return head1;*/
        ListNode* temp=head;
        ListNode* prev= NULL;
        ListNode* next= NULL;
        while(temp){
            ListNode* pair= findPair(temp,2);
            if(pair==NULL){
                if(prev!=NULL) prev->next=temp;
                break;
            }
            next= pair->next;
            pair->next=NULL;
            Reverse(temp);
            if(temp==head){
                head=pair;
            }
            else prev->next=pair;
            prev=temp;
            temp=next;
        }
        return head;
        
    }
};