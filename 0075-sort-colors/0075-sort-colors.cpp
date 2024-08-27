class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,j,n;
        n=nums.size();
        for(i=0;i<n;i++){
           for(j=0;j<n-i-1;j++){
               if(nums[j]>nums[j+1]){
                   swap(nums[j],nums[j+1]);
               }
           } 
        }
    }
};