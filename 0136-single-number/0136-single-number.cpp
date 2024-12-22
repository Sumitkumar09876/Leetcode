class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int store=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            store=store^nums[i];
        }
        return store;
    }
};