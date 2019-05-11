#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define OPEN '('
#define CLOSE ')'

int main(void)
{
    string arrangement; cin >> arrangement;
    
    int answer = 0;
    char before;
    vector<char> bucket;
    for (const auto letter : arrangement) {
        // MARK: - 현재의 문자가 '('인 경우에는 Stack에 넣어준다.
        if (letter == OPEN) { bucket.push_back(letter); }
        // MARK: - 현재의 문자가 ')'인 경우에는 Stack에서 제거한다.
        else {
            // MARK: - Stack이 비어있지 않고 괄호의 쌍이 맞는 경우
            if (!bucket.empty() && bucket.back() == OPEN) { 
                bucket.pop_back();
                // MARK: - 이전의 괄호가 '('인 경우에는 레이저이다.
                answer += (before == OPEN) ? bucket.size() : 1;
            }
        }
        // MARK: - 이전의 문자를 통하여 레이저인지 막대기인지를 구별한다.
        before = letter;
    }
    
    cout << answer << endl;
    
    return 0;
}
