#include <string>
#include <locale>
#include <iostream>
#include <algorithm>
using namespace std;

#define STRING_PAIR pair<string, string>

const bool printAnswer(string first, string second) { 
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());
	return first == second; 
}

int main(void)
{	
	// MARK: - 단어는 알파벳 소문자로만 이루어져 있다.
	int number = 0; cin >> number; cin.ignore();

	// MARK: - 어구전철(語句轉綴) 또는 애너그램(anagram)은 단어나 문장을 구성하고 있는 문자의 순서를 바꾸어 다른 단어나 문장을 만드는 놀이이다. 
	// 어구전철을 잘 아는 사람들끼리 암호문으로 어구전철을 사용할 수도 있지만 그렇지 못할 경우도 많다. 그 이유는 어구전철은 여러 자의적 해석이 가능하기 때문이다.
	for (int ii = 0; ii < number; ii++) {
		STRING_PAIR input = make_pair(string(), string());
		cin >> input.first >> input.second;

		if (printAnswer(input.first, input.second)) { cout << input.first << " & " << input.second << " are anagrams." << endl; }
		else { cout << input.first << " & " << input.second << " are NOT anagrams." << endl; }
	}

	return 0;
} 
