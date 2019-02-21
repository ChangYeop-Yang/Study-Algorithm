#include <vector>
using namespace std;

#define LONG long long

class Solution {
    public:
        int countPrimes(int n) {
    
            int answer = 0;        
            
            vector<bool> isPrime = vector<bool>(n + 1);
            
            for (LONG ii = 2; ii < n; ii++) {
                if (isPrime[ii] == false) {
                    answer++;
                    for (LONG jj = ii * ii; jj <= n; jj += ii) { isPrime[jj] = true; }   
                }
            }
            
            return answer;
        }
};
