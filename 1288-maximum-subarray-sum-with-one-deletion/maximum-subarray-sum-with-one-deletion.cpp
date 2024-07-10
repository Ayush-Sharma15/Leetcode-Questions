class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0]; // edge case for single element

        // Initialize prefix and suffix arrays
        vector<int> ps(n), ss(n);
        ps[0] = arr[0];
        ss[n - 1] = arr[n - 1];

        // Fill prefix sum array
        for (int i = 1; i < n; i++) {
            ps[i] = max(arr[i], ps[i - 1] + arr[i]);
        }

        // Fill suffix sum array
        for (int i = n - 2; i >= 0; i--) {
            ss[i] = max(arr[i], ss[i + 1] + arr[i]);
        }

        // Initialize result as the maximum element in ps array (no deletion case)
        int res = *max_element(ps.begin(), ps.end());

        // Check maximum sum with one deletion
        for (int i = 1; i < n - 1; i++) {
            res = max(res, ps[i - 1] + ss[i + 1]);
        }

        // Debug output
        for (int i = 0; i < n; ++i) {
            cout << "ps[" << i << "] = " << ps[i] << endl;
        }
        for (int i = 0; i < n; ++i) {
            cout << "ss[" << i << "] = " << ss[i] << endl;
        }
        cout << "max_sum = " << res << endl;

        return res;
    }
};
