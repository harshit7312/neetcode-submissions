class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // A valid triplet requires at least 3 elements
        if (n < 3) return result;

        // Step 1: Sort the array to enable two-pointers and easily skip duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Early exit: if the current number is positive, we can never reach a sum of 0
            if (nums[i] > 0) break;

            // Skip duplicate values for the first element of our triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            // Step 2: Use two pointers to find pairs that sum to `target`
            while (left < right) {
                int current_sum = nums[left] + nums[right];

                if (current_sum == target) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicate values for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inward after processing a match
                    left++;
                    right--;
                } 
                else if (current_sum < target) {
                    left++; // We need a larger sum, move left pointer right
                } 
                else {
                    right--; // We need a smaller sum, move right pointer left
                }
            }
        }

        return result;
    }
};
