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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next==NULL) return {0};
        vector<int>res;
        stack<int>st;
        ListNode* temp= head;
        while(temp){
        res.push_back(temp->val);
        temp=temp->next;
        }
        if(res.empty()) return {0};
        vector<int>nge(res.size());
        for(int i=res.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=res[i]){
                st.pop();
            }
            if(st.empty()) nge[i]=0;
            else nge[i]=st.top();
            st.push(res[i]);
        }
        return nge;
    }
};