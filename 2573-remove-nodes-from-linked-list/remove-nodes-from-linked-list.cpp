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
    ListNode* removeNodes(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp!=NULL){
           while(!ans.empty() && ans.back()<temp->val){
            ans.pop_back();
           }
           ans.push_back(temp->val);
           temp=temp->next;
        }
        ListNode* head1=new ListNode(ans[0]);
        ListNode* mover=head1;
        for(int i=1;i<ans.size();i++){
           ListNode*temp=new ListNode(ans[i]);
           mover->next=temp;
           mover=temp;
        }
        
        return head1;
    }
};