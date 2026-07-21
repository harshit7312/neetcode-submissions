class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         unordered_map<int, int> valueToIndex;

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            int complement = target - currentNum;

            // Check if the complement exists in the hash map
            if (valueToIndex.find(complement) != valueToIndex.end()) {
                // Found the pair, return their indices
                return {valueToIndex[complement], i};
            }

            // Store current number and its index in the hash map
            valueToIndex[currentNum] = i;
        }

        // This line should never be reached if input guarantees a solution
        return {};
    }
};
