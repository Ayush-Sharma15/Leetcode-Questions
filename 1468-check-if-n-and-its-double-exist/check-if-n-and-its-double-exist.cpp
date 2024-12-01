class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(int i=0;i<arr.size();i++)
{
    if(st.count(arr[i]*2) or  (arr[i]%2==0 and st.count(arr[i]/2)))
    return true;
    else{
        st.insert(arr[i]);
    }
}
return false;    
}
};