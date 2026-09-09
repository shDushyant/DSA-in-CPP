class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> st;

        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> PSE(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> pse = PSE(arr);

        long long total = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution = left * right * arr[i];

            total = (total + contribution) % mod;
        }

        return total;
    }
};