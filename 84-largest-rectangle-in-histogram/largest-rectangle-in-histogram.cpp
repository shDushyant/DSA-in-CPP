class Solution {
public:
    /*vector<int> NSE(vector<int>& heights) {
        vector<int> nse(heights.size());
        stack<int> st;

        for(int i = heights.size()-1; i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? heights.size() : st.top();

            st.push(i);  
        }

        return nse;
    }

    vector<int> PSE(vector<int>& heights) {
        vector<int> pse(heights.size());
        stack<int> st;

        for(int i = 0;i<heights.size();i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);  
        }

        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = PSE(heights);
        vector<int> nse = NSE(heights);

        int maxi = 0;

        for(int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;*/
        int largestRectangleArea(vector<int>& heights) {
    int maxi = 0;
    stack<int> st;

    for(int i = 0; i < heights.size(); i++) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {

            int temp = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, heights[temp] * (nse - pse - 1));
        }

        st.push(i);
    }

    // Process remaining elements
    while(!st.empty()) {

        int temp = st.top();
        st.pop();

        int nse = heights.size();
        int pse = st.empty() ? -1 : st.top();

        maxi = max(maxi, heights[temp] * (nse - pse - 1));
    }

    return maxi;
}
};