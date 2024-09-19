class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;  
        }
        
        map<char,int> m1 , m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
      
        for(auto x: m1){
            char ch = x.first;
            if(x.second != m2[ch])
            return false;
        }

        return true;
    }
};
  