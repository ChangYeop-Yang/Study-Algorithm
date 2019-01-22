#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {
		
		int person = 0; cin >> person;

		vector<PAIR> score = vector<PAIR>(person);
		for (int ii = 0; ii < person; ii++) { scanf("%d %d", &score[ii].first, &score[ii].second); }
		sort(score.begin(), score.end());

		PAIR paper = score.front(); // 서류 상위권자
		PAIR presenter = make_pair(0, 0); // 면접 상위권자
		for (int ii = 0; ii < person; ii++) { if (score[ii].second <= 1) { presenter = score[ii]; } }

		int answer = 1;
		for (int ii = 1; ii < person; ii++) {
			if (score[ii] == presenter) { answer++; continue; } // 면접 상위권자인 경우 자동적으로 합격
			// 서류 상위권자보다 면접 순위가 높으면서 면접 상위권자보다 서류 순위가 높은 사람
			if (paper.second > score[ii].second && presenter.first > score[ii].first) { paper = score[ii]; answer++; }
			// 오름차순 정렬이므로 합격자를 갱신함으로써 자동적으로 그 아래 순위는 배제
		}

		cout << answer << endl;
	}

	return 0;
}