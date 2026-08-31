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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans;
        vector<int>store;
        while(temp!=NULL){
           ans.push_back(temp->val);
           temp=temp->next;
        }
        int n=ans.size();
        if(n<=3) return {-1,-1};
        int j=1;
        while(j<n-1){
            if((ans[j]>ans[j+1]&& ans[j]>ans[j-1]) || (ans[j]<ans[j+1]&& ans[j]<ans[j-1])){
              store.push_back(j+1);
            }
            j++;
        }
        if(store.size()<=1) return {-1,-1};
        int mini= INT_MAX;
        for(int i=1;i<store.size();i++){
            mini=min(mini,store[i]-store[i-1]);
        }
        int maxi=store[store.size()-1]-store[0];
        return {mini,maxi};
    }
};