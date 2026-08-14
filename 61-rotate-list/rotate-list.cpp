class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> v;
        ListNode* temp = head;

        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int n = v.size();
        k = k % n;

        // Reverse entire array
        reverse(v.begin(), v.end());

        // Reverse first k elements
        reverse(v.begin(), v.begin() + k);

        // Reverse remaining elements
        reverse(v.begin() + k, v.end());

        // Build linked list
        ListNode* newHead = new ListNode(v[0]);
        temp = newHead;

        for (int i = 1; i < n; i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }

        return newHead;
    }
};