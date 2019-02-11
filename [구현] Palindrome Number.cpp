#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        pair<string, string> comp = make_pair(to_string(x), to_string(x));
        std::reverse(comp.first.begin(), comp.first.end());
        
        return comp.first == comp.second ? true : false;
    }
};
