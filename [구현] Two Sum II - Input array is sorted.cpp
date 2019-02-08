class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int length = numbers.size();
        for (int ii = 0; ii < length; ii++) {
            for (int jj = 0; jj < ii; jj++) {
                if (numbers[ii] + numbers[jj] == target) { return {jj + 1, ii + 1}; }
            }
        }
        
        return {0, 0};
    }
};