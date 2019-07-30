#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;

#define BIT_SIZE 16 /* (1 ≦ N ≦ 16) */
#define INT_PAIR pair<int, int>

const string convertBinaryDigit(const INT_PAIR value, const int n) {

	bitset<BIT_SIZE> binary(value.first);
	binary |= bitset<BIT_SIZE>(value.second);

	const string answer = binary.to_string(' ', '#');
	return string(answer.rbegin(), answer.rbegin() + n);
}

// 원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

	vector<string> answer;
	
	for (int index = 0; index < arr1.size(); index++) {
		const INT_PAIR digit = make_pair(arr1[index], arr2[index]);

		string map = convertBinaryDigit(digit, n);
		std::reverse(map.begin(), map.end());

		answer.push_back(map);
	}

	return answer;
}
