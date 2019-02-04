#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {        
		string num = to_string(x);
		std::reverse(num.begin(), num.end());
        
        long answer = atol(num.c_str());
        
        if (answer > INT_MAX || answer < INT_MIN) { return 0; }
        return x < 0 ? answer * - 1 : answer;
	}
};
