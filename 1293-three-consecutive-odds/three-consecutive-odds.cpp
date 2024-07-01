class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0,n=arr.size(),k=0;
        for(auto x: arr){
            if(x%2!=0){
                k++;
            }
            else{
                k=0;
            }
            if(k==3)
            return true;
        }
        return false;
    }
};