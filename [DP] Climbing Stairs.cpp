class Solution {
public:
    int climbStairs(int n) {
        
        // Each time you can either climb 1 or 2 steps. 피보나치 수열 DP
        
        vector<int> stairs = vector<int>(n + 1);
        
			stairs[1] = 1; stairs[2] = 2;
			for (int ii = 3; ii <= n; ii++) {
				stairs[ii] = stairs[ii - 1] + stairs[ii - 2];
			}
		
			return stairs[n];
    }
};