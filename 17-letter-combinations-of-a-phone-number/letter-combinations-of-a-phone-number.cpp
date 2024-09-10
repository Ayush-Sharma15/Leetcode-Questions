class Solution {
public:

    void func(int ind , string digits , map<char, string> & mp , vector<string>&ans , string s){
        if(digits.length() == s.length()){
            ans.push_back(s);
            return;
        }

        string s1 = mp[digits[ind]];
        for(int i=0;i<s1.length();i++)
        
        func(ind+1 , digits , mp , ans , s + s1[i]);


    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        return {};
        map<char , string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string s;

        func(0 , digits , mp , ans , s);

        return ans;
    }
};