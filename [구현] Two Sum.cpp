#define INT_PAIR pair<int, int>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            
            int length = nums.size();
            for (int ii = 0; ii < length; ii++) {
                for (int jj = 0; jj < ii; jj++) {
                    if (nums[ii] + nums[jj] == target) { return {jj, ii}; }
                }
            }
            
            return {0, 0};
        }
};