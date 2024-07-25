class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0 and nums[0]!=target)
        return -1;
       int start=0,end=nums.size()-1,mid;
       while(start<=end){
        mid= start + ((end-start)/2);
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]<target)
        start=mid+1;
        else
        end=mid-1;
       } 
       return -1;
    }  
};