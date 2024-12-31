class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int pivot = -1;
        int index;

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = nums[i];
                index = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = size - 1; i >= 0; i--) {
                if (nums[i] > pivot) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
