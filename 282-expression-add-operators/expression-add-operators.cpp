#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void func(int ind, string num, long long target, vector<string>& ans, string s, long long sum, long long lastValue) {
        
        if (ind == num.length()) {
            if (sum == target) {
                ans.push_back(s);  
            }
            return;
        }

        for (int i = ind; i < num.length(); i++) {
            if (i > ind && num[ind] == '0') break;

            string currentNumStr = num.substr(ind, i - ind + 1);
            long long currentNum = stoll(currentNumStr);

            if (ind == 0) {
                func(i + 1, num, target, ans, currentNumStr, currentNum, currentNum);
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

