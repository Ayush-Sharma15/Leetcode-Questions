#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void func(int ind, string num, long long target, vector<string>& ans, string s, long long sum, long long lastValue) {
        // Base case: if we reach the end of the string
        if (ind == num.length()) {
            if (sum == target) {
                ans.push_back(s);  // Add valid expression to the result
            }
            return;
        }

        // Try all possible splits
        for (int i = ind; i < num.length(); i++) {
            // Avoid numbers with leading zero
            if (i > ind && num[ind] == '0') break;

            // Current number in string format
            string currentNumStr = num.substr(ind, i - ind + 1);
            long long currentNum = stoll(currentNumStr);

            // If this is the first number, we simply recurse
            if (ind == 0) {
                func(i + 1, num, target, ans, currentNumStr, currentNum, currentNum); // No operator before first number
            } else {
                func(i + 1, num, target, ans, s + "+" + currentNumStr, sum + currentNum, currentNum);

                func(i + 1, num, target, ans, s + "-" + currentNumStr, sum - currentNum, -currentNum);

                func(i + 1, num, target, ans, s + "*" + currentNumStr, sum - lastValue + lastValue * currentNum, lastValue * currentNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        
        func(0, num, target, ans, "", 0, 0);
        return ans;
    }
};

