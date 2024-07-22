class Solution {
public:
    vector<string> sortPeople(vector<string>& a, vector<int>& h) {
        map<int,string> mp;
        vector<string>ans;
        
        for(int i=0;i<a.size();i++)mp[h[i]]=a[i];

        for(auto x:mp){
            ans.push_back(x.second);
        }

        reverse(ans.begin(),ans.end());

        

        return ans;

    }
};