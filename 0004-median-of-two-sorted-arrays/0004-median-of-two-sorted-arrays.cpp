class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? numeric_limits<int>::min() : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? numeric_limits<int>::max() : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? numeric_limits<int>::min() : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? numeric_limits<int>::max() : nums2[partition2];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If the total number of elements is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;  // Move towards the left in nums1
            } else {
                low = partition1 + 1;   // Move towards the right in nums1
            }
        }
        
        // If the input arrays are invalid, return 0.0 (this line should never be reached)
        return 0.0;
    }
};