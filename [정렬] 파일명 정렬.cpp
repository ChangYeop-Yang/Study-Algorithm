#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define STR_FILE_PAIR pair<string, File>

const string removeZero(string number) {

	auto end = number.begin();
	while (number.end() != end && *end == 48) { end++; }

	// 문자열 앞에 숫자 0을 제거한다.
	if (number.begin() != end) {
		number.erase(number.begin(), end);
	}

	return number.empty() ? "0" : number;
}

const bool isDigit(const char letter) {
	return letter >= 48 && letter <= 57;
}

typedef struct file {

	string head;
	string number;

	file(string name) {

		string::iterator str_iter;

		for (auto begin = name.begin(); begin != name.end(); begin++) {
			const auto letter = *begin;
			// HEAD는 숫자가 아닌 문자로 이루어져 있으며, 최소한 한 글자 이상이다.
			if (isDigit(letter)) { str_iter = begin; break; }
		}

		// 문자열 비교 시 대소문자를 구분 하지 않는다.
		this->head = string(name.begin(), str_iter);
		std::transform(this->head.begin(), this->head.end(), this->head.begin(), ::toupper);

		// NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자로 이루어져 있으며, 앞쪽에 0이 올 수 있다. 0부터 99999 사이의 숫자로, 00000이나 0101 등도 가능하다.
		for (; str_iter != name.end(); str_iter++) {
			const auto letter = *str_iter;

			/* 
				파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬한다. 
				9 < 10 < 0011 < 012 < 13 < 014 순으로 정렬된다. 
				숫자 앞의 0은 무시되며, 012와 12는 정렬 시에 같은 같은 값으로 처리된다.
			*/
			if ( isDigit(letter) && this->number.size() < 5 ) { 
				this->number += letter; 
				// ※ CAPTION - NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자이다.
			} else {
				break;
			}
		}

		this->number = removeZero(this->number);
	}

} File;

const bool compare(const STR_FILE_PAIR & left, const STR_FILE_PAIR & right) {
	const pair<File, File> target = std::make_pair(left.second, right.second);

	if (target.first.head.compare(target.second.head) == 0) {
		return std::stoi(target.first.number) < std::stoi(target.second.number);
	} else {
		return target.first.head < target.second.head;
	}
}

vector<string> solution(vector<string> files) {

	vector<STR_FILE_PAIR> bucket;
	for (const auto val : files) {
		const STR_FILE_PAIR item = std::make_pair(val, File(val));
		bucket.push_back(item);
	}
	
	std::stable_sort(bucket.begin(), bucket.end(), compare);

	vector<string> answer;
	for (const auto val : bucket) {
		answer.push_back(val.first);
	}

	return answer;
}
