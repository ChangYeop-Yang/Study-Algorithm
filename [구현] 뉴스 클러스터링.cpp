#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define UNORDER_MAP std::unordered_map<string, int>

/*	ⓐ
	자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다.
	두 집합 A, B 사이의 자카드 유사도 J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.
*/

/*	ⓑ
	입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다.
	이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
	예를 들어 ab+가 입력으로 들어오면, ab만 다중집합의 원소로 삼고, b+는 버린다.
*/

const bool checkAlpabat(const char letter) {
	return letter >= 65 && letter <= 90;
}

UNORDER_MAP split(const string str) {

	UNORDER_MAP result;

	for (int index = 0; index < str.size() - 1; index++) {
		
		// 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
		if (!checkAlpabat(str[index]) || !checkAlpabat(str[index + 1])) { continue; }

		string letter;
		letter += str[index];
		letter += str[index + 1];

		if (result.find(letter) != result.end()) { result[letter]++; }
		else { result.insert(std::make_pair(letter, 1)); }
	}

	return result;
}

const double unionSet(const UNORDER_MAP & first, const UNORDER_MAP & second) {

	UNORDER_MAP bucket = first;
	
	for (const auto value : second) {
		const string key = value.first;

		if (bucket.find(key) != bucket.end()) {
			bucket[key] = std::max(bucket[key], value.second);
		} else {
			const auto item = std::make_pair(key, 1);
			bucket.insert(item);
		}
	}

	double count = 0;
	for (const auto item : bucket) { count += item.second; }

	return count;
}

const double intersectionSet(UNORDER_MAP first, UNORDER_MAP second) {

	double answer = 0.0;

	for (const auto value : first) {
		const string key = value.first;

		if (second.find(key) != second.end()) {
			answer += std::min(first[key], second[key]);
		}
	}

	return answer;
}

int solution(string str1, string str2) {

	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	const auto str1_vec = split(str1);
	const auto str2_vec = split(str2);

	const double intersection = intersectionSet(str1_vec, str2_vec);
	const double uni = unionSet(str1_vec, str2_vec);

	int answer = 0;
	
	// ※ CAPTION - 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.
	if (uni == 0 && intersection == 0) { answer = 65536; }
	else { answer = (intersection / uni) * 65536; }

	// 다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. AB와 Ab, ab는 같은 원소로 취급한다.

	// 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.
	return answer;
}
