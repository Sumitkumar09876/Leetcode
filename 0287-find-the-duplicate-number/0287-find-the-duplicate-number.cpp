class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    // Create an empty set to store seen elements
    unordered_set<int> seen;
    
    // Iterate through the vector
    for (int num : nums) {
      // If the element is already in the set, it's a duplicate
      if (seen.count(num)) {
        return num;
      }
      // Add the element to the set
      seen.insert(num);
    }
    
    // No duplicate found
    return -1; // Or throw an error
  }
};
