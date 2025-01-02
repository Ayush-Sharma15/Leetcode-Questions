class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int n = words.size(), m = queries.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            int t = words[i].length();
            if (vowels.count(words[i][0]) && vowels.count(words[i][t - 1])) {
                v[i] = 1;
            }
        }
    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + v[i];
    }

    vector<int> result;
    for (const auto& query : queries) {
        int l = query[0]; 
        int r = query[1]; 
        int sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l - 1];
        result.push_back(sum);
    }
    return result;
    }
};