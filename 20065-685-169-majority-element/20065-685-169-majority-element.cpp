class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>store;
        int n=nums.size();
        for(int i=0;i<n;i++){
            store[nums[i]]++;
        }
        for(auto& it:store){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};