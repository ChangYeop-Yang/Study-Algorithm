#include <deque>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

#define MAX_N 3

const int findDigit(int index, const string dartResult) {

	deque<char> digit;

	while (index >= 0) {
		if (dartResult[--index] < 48 || dartResult[index] > 57) { break; }
		digit.push_front(dartResult[index]);
	}

	string value = string(digit.begin(), digit.end());
	return std::stoi(value);
}

int solution(string dartResult) {

	/* 
		옵션으로 스타상(*), 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 
		아차상(#) 당첨 시 해당 점수는 마이너스된다. 
	*/
	vector<int> answer = vector<int>(MAX_N);
	
	// 점수는 0에서 10 사이의 정수이다. 1D 2S# 10S}
	vector<int> digit_pos;
	for (int index = 0; index < dartResult.size(); index++) {
		// 문자의 아스키 값을 통하여 영어 대문자를 확인하여 구분한다.
		if (dartResult[index] >= 65 && dartResult[index] <= 90) { 
			digit_pos.push_back(index);
		}
	}

	findDigit(digit_pos.back(), dartResult);

	return std::accumulate(answer.begin(), answer.end(), 0);
}
