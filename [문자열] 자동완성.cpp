#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 26
// 모든 단어는 알파벳 소문자로 구성된다.
#define TO_NUMBER(X) X - 'a'

typedef struct TriNode {

	int count = 0;              // 현재의 학습 된 문자가 몇개인지 알려주는 변수
	bool terminate = false;     // 문자의 끝을 알려주는 변수
	TriNode * child[MAX_LEN];

	TriNode() {
		memset(child, 0, sizeof(child));
	}

	~TriNode() {
		for (auto & node : child) {
			if (node) { delete node; }
		}
	}

	void insert(const char * key) {
        
        // 마지막 문자인 경우를 표시한다.
		if (*key == 0) { this->terminate = true; }
		else {
            // 소문자를 인덱스로 변환한다.
			const int next = TO_NUMBER(*key);
            
            // 현재 문자가 생성되어 있지 않은 경우 새로운 문자 인덱스 트리를 생성한다.
			if (child[next] == NULL) { child[next] = new TriNode(); }
            
            // 문자의 수를 증가시켜주며 다음 문자를 바탕으로 인덱스 트리를 생성한다.
			child[next]->count++;
			child[next]->insert(key + 1);
		}
	}

	int find(const char * key, const int cnt) {

		const int next = TO_NUMBER(*key);

        /* 
            해당 문자가 끝 문자인 경우에는 그 하나 전 단어만 입력하면 되기 때문에 현재 입력에서            하나를 빼어준다.
        */
		if (*key == 0 || child[next] == NULL) { return cnt - 1; }
		
        /* 
            해당 문자로 이어지는 문자열이 없는 경우 탐색을 종료한다. 왜냐하면 해당 문자로 시작하는 
            문자는 완전 다른 트리에 속하므로 다른 문자로 보아야 하기 때문이다.
            (이부분이 이해가 되지 않아서 많이 시간을 낭비함.)
        */
		if (child[next]->count == 1) { return cnt; }

		return child[next]->find(key + 1, cnt + 1);
	}

} Tri;

int solution(vector<string> words) {

	Tri * tri = new Tri();
	for (const auto word : words) {
		const auto c_word = word.c_str();
		tri->insert(c_word);
	}

	int answer = 0;
	for (const auto word : words) {
		const auto c_word = word.c_str();
        // 현재의 문자는 하나씩 가지고 있으므로 1로 초기값을 넣어준다.
		answer += tri->find(c_word, 1);
	}

    // 학습된 단어들을 순서대로 찾을 때 몇 개의 문자를 입력하면 되는지 계산한다.
    delete tri;
	return answer;
}
