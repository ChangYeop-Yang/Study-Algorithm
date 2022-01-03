#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    
    // 짧은 길이의 숫자를 정렬합니다.
    sort(phone_book.begin(), phone_book.end());
    
    for (int index = 0; index < phone_book.size() - 1; index++) {
        const auto currentLength = phone_book[index].length();
        const string nextKey = phone_book[index + 1].substr(0, currentLength);
        
        if (phone_book[index] == nextKey) { return false; }
    }
    
    return true;
}
