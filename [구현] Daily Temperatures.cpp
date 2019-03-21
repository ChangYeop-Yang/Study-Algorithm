#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

#define IS_ZERO 0

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {

            vector<int> answer;
            int maxTemp = INT_MIN;
            
            // 최대값의 온도를 찾는다.
            for (const auto daily : T) { maxTemp = std::max(maxTemp, daily); }
            
            for (int ii = 0; ii < T.size(); ii++) {
                
                // Case Not Contain Higher Temperature.
                if (maxTemp <= T[ii]) { answer.push_back(IS_ZERO); continue; }
                
                int time = 0;
                bool isCheck = true;
                for (int jj = ii + 1; jj < T.size(); jj++, time++) { 
                    if (T[ii] < T[jj]) { answer.push_back(time + 1); isCheck = false; break; }
                }
                
                if (isCheck) { answer.push_back(IS_ZERO); }
            }
            
            while (T.size() != answer.size()) { answer.push_back(0); }
            
            return answer;
        }
};