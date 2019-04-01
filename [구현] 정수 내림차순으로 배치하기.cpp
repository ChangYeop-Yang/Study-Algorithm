#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    
    string answer = std::to_string(n);
    std::sort(answer.begin(), answer.end(), greater<char>());
    
    return stoll(answer);
}
