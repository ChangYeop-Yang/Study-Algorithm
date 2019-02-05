#include <algorithm>

#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > answer;
        answer.push_back(nums);
        
        while (true) {
            int temp = 0;
            int length = nums.size() - 1;

            int ii = length;
            while (nums[ii] <= nums[ii - 1]) { ii--; }

            // Case Last Permutation
            if (ii <= 0) { break; }

            int jj = length;
            while (jj >= ii && nums[jj] <= nums[ii - 1]) { jj--; };
            SWAP(nums[ii - 1], nums[jj], temp);

            for (int tt = length; tt > ii; ii++, tt--) {
                SWAP(nums[ii], nums[tt], temp);
            }

            answer.push_back(nums);
        }
        
        return answer;
    }
};