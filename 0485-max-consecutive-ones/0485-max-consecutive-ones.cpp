class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,max_cnt=INT_MIN;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            max_cnt=max(max_cnt,cnt);
        }
        return max_cnt;
    }
};