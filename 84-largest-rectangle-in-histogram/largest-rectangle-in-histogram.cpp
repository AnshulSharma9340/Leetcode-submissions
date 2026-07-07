class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> arr1(n);
        vector<int> arr2(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                arr1[i] = -1;
            } else {
                arr1[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();  // reset stack for second pass

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                arr2[i] = n;
            } else {
                arr2[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = arr2[i] - arr1[i] - 1;
            int area = heights[i] * width;
            ans = max(area, ans);
        }

        return ans;
    }
};