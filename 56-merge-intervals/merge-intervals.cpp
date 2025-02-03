class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        stack<int> st;
        st.push(intervals[0][0]); 
        st.push(intervals[0][1]); 

        for (int i = 1; i < intervals.size(); i++) {
            int endTop = st.top(); 
            int startNext = intervals[i][0];
            int endNext = intervals[i][1];

            if (startNext <= endTop) { 
                
                st.pop();
                st.push(max(endTop, endNext));
            } else {
                
                st.push(startNext);
                st.push(endNext);
            }
        }
        vector<vector<int>> ans;
        while (!st.empty()) {
            int endTime = st.top(); st.pop();
            int startTime = st.top(); st.pop();
            ans.push_back({startTime, endTime});
        }

        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};
