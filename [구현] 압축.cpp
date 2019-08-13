#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*	LZW 압축은 다음 과정을 거친다.

	ⓐ 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
	ⓑ 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
	ⓒ w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
	ⓓ 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
	ⓔ 단계 2로 돌아간다.
*/

#define INT_PAIR pair<int, int>

// ※ CAPTION - 압축 알고리즘이 영문 대문자만 처리한다고 한다.
vector<int> solution(string msg) {

	vector<int> answer;
	unordered_map<string, int> dict;

	// ⓐ 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
	for (int ii = 'A'; ii <= 'Z'; ii++) {
		const auto key = std::make_pair(string(1, ii), ii - 'A' + 1);
		dict.insert(key);
	}
	
	string word = string();
	for (int ii = 0; ii < msg.size(); ii++) {
		// ⓔ 단계 2로 돌아간다.
		word += msg[ii];
		
		// ⓑ 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
		if (dict.find(word) == dict.end()) {
			const auto key = std::make_pair(word, dict.size() + 1);
			dict.insert(key);

			// ⓒ w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
			word = word.substr(0, word.size() - 1);
			answer.push_back(dict[word]);
			word.clear(), ii--;
		}
	}

	// ⓓ 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
	if (word.size() > 0) { answer.push_back(dict[word]); }

	// 주어진 문자열을 압축한 후의 사전 색인 번호를 배열로 출력하라.
	return answer;
}
