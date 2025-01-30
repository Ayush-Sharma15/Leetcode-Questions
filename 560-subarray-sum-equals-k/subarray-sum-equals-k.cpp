#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;  // Stores prefix sum frequencies
        long long sum = 0;
        int count = 0;
        
        mp[0] = 1;  // Base case: There is one way to have sum 0 (empty subarray)

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Calculate prefix sum
            long long rem = sum - k; // Find the required sum to remove
            
            // If rem exists, add its count to total subarrays
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            // Store the frequency of the current prefix sum
            mp[sum]++;
        }
        return count;
    }
};
