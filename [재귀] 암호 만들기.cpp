#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

string encrypt;

const bool checkSentence(const string sentence) {
	
	pair<int, int> vowel = make_pair(0, 0);

	for (const char letter : sentence) {
		switch (letter) {
			case 'a': case 'e': case 'i': case 'o': case 'u': vowel.first++; break;
			default: vowel.second++; break;
		}
	}

	return vowel.first >= 1 && vowel.second >= 2 ? true : false;
}

void createEncrypt(int index, const int goal, string bucket) {
	
	// 구하고자 하는 암호문의 길이가 구해진 경우
	if (bucket.length() == goal) {
		// 모음과 자음 확인
		if (checkSentence(bucket)) { cout << bucket << endl; return; }
		return;
	}

	// Index가 주어진 평문의 길이보다 커진 경우 종료
	if (index >= encrypt.size()) { return; }

	createEncrypt(index + 1, goal, bucket + encrypt[index]); // index 번째 알파벳을 사용하는 경우
	createEncrypt(index + 1, goal, bucket); // index 번째 알파벳을 사용하지 않는 경우
}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

    encrypt = string("", input.second);
	for (int ii = 0; ii < input.second; ii++) { cin >> encrypt[ii]; }

	sort(encrypt.begin(), encrypt.end());
	createEncrypt(0, input.first, string());

	return 0;
}

/* 순열을 이용한 방법
int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	string encrypt = string("", input.second);
	for (int ii = 0; ii < input.second; ii++) { cin >> encrypt[ii]; }
	sort(encrypt.begin(), encrypt.end());
	
	vector<int> permutation = vector<int>(input.second);
	for (int ii = 0; ii < input.first; ii++) { permutation[ii] = 1; }
	sort(permutation.begin(), permutation.end());

	vector<string> answer;
	do {

		string sentence;
		for (int ii = 0; ii < input.second; ii++) {
			if (permutation[ii] == 0) { continue; }
			sentence.push_back(encrypt[ii]);
		}

		if (checkSentence(sentence)) { answer.push_back(sentence); }

	} while (next_permutation(permutation.begin(), permutation.end()));

	for (auto begin = answer.rbegin(); begin != answer.rend(); begin++) { cout << *begin << endl; }

	return 0;
}
*/