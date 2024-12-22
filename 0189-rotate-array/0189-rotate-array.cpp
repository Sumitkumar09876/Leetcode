class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        vector<int>store(size);
        k=k%size;
        for(int i=0;i<k;i++){
            store[i]=nums[size-k+i];
        }
        for(int i=k;i<size;i++){
            store[i]=nums[i-k];
        }
        nums=store;
    }
};