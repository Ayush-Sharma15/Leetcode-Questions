class Solution {
public:
    int addRungs(vector<int>& arr, int dist) {
        int n=arr.size(),count=0, step = 0;
        for(int i = 0; i < n; i++){
            if((arr[i]-step)>dist){
                count += (arr[i]- step - 1)/dist;
                step = arr[i];
            }
            else
            step = arr[i];
        }
        return count;
    }
};