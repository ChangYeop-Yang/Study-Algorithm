#include <iostream>
#include <algorithm>
using namespace std;

#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {

            int temp = 0;
            int length = matrix.size() - 1;
            
            //reverse(matrix.begin(), matrix.end());
            for (int ii = 0; ii <= length / 2; ii++) {
                for (int jj = 0; jj <= length; jj++) { SWAP(matrix[ii][jj], matrix[length - ii][jj], temp); }
            }
            
            for (int ii = 0; ii <= length; ii++) {
                for (int jj = ii + 1; jj <= length; jj++) {
                    SWAP(matrix[ii][jj], matrix[jj][ii], temp);
                }
            }
        }
};