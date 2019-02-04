#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        
        // Case "words and 987"
        if (str.front() - '0' > 9) { return 0; }
        
        // Case Nomal
        string bucket;
        for (const auto letter : str) {
            if (letter - '0' > 9) { break; }
            bucket.push_back(letter);
        }
        
        long answer = atol(bucket.c_str());
        
        // Case "-91283472332"
        if (answer > INT_MAX) { return INT_MAX; }
        // Case "91283472332"
        else if (answer < INT_MIN) { return INT_MIN; }
        
        // Case Nomal
        return answer;
    }
};
