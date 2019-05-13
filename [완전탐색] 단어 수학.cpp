#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MAX_N 9

const int convertInteger(const string word, const vector<int> &board) {
    int value = 0;
    for (const char letter : word) { value = value * 10 + board[letter]; }
    return value;
}

int main(void)
{
    // MARK: - 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다.
    int answer = 0;
    int number = 0; cin >> number;

    vector<int> board(256, -1);
    vector<char> chs;
    vector<string> words = vector<string>(number);
    for (int ii = 0; ii < number; ii++) { 
        cin >> words[ii]; 
        for (const auto letter : words[ii]) { board[letter] = 0; chs.push_back(letter); }
    }
    sort(chs.begin(), chs.end());
    chs.erase(unique(chs.begin(), chs.end()), chs.end());

    vector<int> digits;
    // MARK: - 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.
    for (int ii = 0; ii < chs.size(); ii++) { digits.push_back(MAX_N - ii); }

    do {
        auto begin = digits.begin();
        for (const auto ch : chs) { board[ch] = *begin; begin++; }

        int sum = 0;
        for (const auto word : words) {
            sum += convertInteger(word, board);
        }

        // MARK: - 그 수의 합을 최대로 만드는 프로그램을 작성하시오.
        answer = std::max(answer, sum);

    } while (std::prev_permutation(digits.begin(), digits.end()));

    // MARK: - 주어진 단어의 합의 최댓값을 출력한다.
    cout << answer << endl;

    return 0;
}
