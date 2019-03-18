#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            
            for (int kk = 0; kk < A.size(); kk++) {
                std::reverse(A[kk].begin(), A[kk].end());
                for (int ii = 0; ii < A[kk].size(); ii++) { A[kk][ii] = (A[kk][ii] == 0 ? 1 : 0); }
            }
            
            return A;
        }
};
