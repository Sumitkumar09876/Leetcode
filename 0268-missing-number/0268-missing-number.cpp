
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return size;
    }
};