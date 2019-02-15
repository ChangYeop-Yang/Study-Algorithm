#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

void reculsiveDFS(int index, vector<bool> & visit, vector<INT_VECTOR> & student, vector<int> & answer) {

	visit[index] = true;

	for (int ii = 0; ii < student[index].size(); ii++) {
		const int there = student[index][ii];
		if (visit[there] == false) { reculsiveDFS(there, visit, student, answer); }
	}

	// DFS 종료시 방문 한 정점의 번호를 저장한다.
	answer.push_back(index);
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> check = vector<int>(input.first);
	vector<bool> visit = vector<bool>(input.first);
	vector<INT_VECTOR> student = vector<INT_VECTOR>(input.first);
	
	INT_PAIR pos = make_pair(0, 0);
	for (int ii = 0; ii < input.second; ii++) {
		scanf("%d %d", &pos.first, &pos.second);
		student[pos.first - 1].push_back(pos.second - 1);

		// 위상정렬의 핵심은 들어오는 간선이 하나도 없는 정점들을 찾아서 결과를 찾는다.
		check[pos.second - 1]++;
	}

	vector<int> answer;
	for (int ii = 0; ii < input.first; ii++) {
		// 방문하지 않은 정점이며 간선이 존재하는 않은 정점
		if (check[ii] == 0 && visit[ii] == false) { reculsiveDFS(ii, visit, student, answer); }
	}

	// DFS 종료한 뒤 기록된 순서를 뒤집으면 위상 정렬의 결과를 얻는다.
	for (auto begin = answer.rbegin(); begin != answer.rend(); begin++) { cout << *begin + 1 << endl; }

	return 0;
}