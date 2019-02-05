#include <algorithm>
using namespace std;

#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int length = nums.size() - 1;
        
        int ii = length;
        while (nums[ii] <= nums[ii - 1]) { ii--; }
        
        // Case Last Permutation
        if (ii <= 0) { reverse(nums.begin(), nums.end()); return; }
        
        int jj = length;
        while (jj >= ii && nums[jj] <= nums[ii - 1]) { jj--; }
        
        int temp = 0;
        SWAP(nums[ii - 1], nums[jj], temp);
        
        for (int qq = length; ii < qq; qq--, ii++) {
            SWAP(nums[ii], nums[qq], temp);
        }
    }
};