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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(int i=0;i<lists.size();i++){
            //ListNode* head= lists[i];
            ListNode* temp= lists[i];
            while(temp){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(arr.empty()) return NULL;
        sort(arr.begin(),arr.end());
        ListNode* head1= new ListNode(arr[0]);
        ListNode* mover= head1;
        for(int i=1;i<arr.size();i++){
            ListNode* temp=new ListNode(arr[i]);
            mover->next=temp;
            mover=temp;
        } 
        return head1;
    }
};