#include <deque>
#include <cstdio>
#include <iostream>
using namespace std;

#define LEN 1000000
#define PAIR pair<int, int>

int path[LEN]; // 경로 값 저장
bool check[LEN]; // 방문 여부

void searchBFS(const int length, const int src) {

	check[src] = true;

	deque<int> deq;
	deq.push_back(src);

	while (!deq.empty()) {

		int index = deq.front(); deq.pop_front();

		if (index * 2 < LEN && check[index * 2] == false) { // 순간이동 한 경우
			check[index * 2] = true;
			path[index * 2] = path[index];
			deq.push_front(index * 2);
		}
		if (index + 1 < LEN && check[index + 1] == false) { // 한 칸 이동한 경우
			check[index + 1] = true;
			path[index + 1] = path[index] + 1;
			deq.push_back(index + 1);
		}
		if (index - 1 >= 0 && check[index - 1] == false) { // 한 칸 뒤로 이동한 경우
			check[index - 1] = true;
			path[index - 1] = path[index] + 1;
			deq.push_back(index - 1);
		}
	}

	cout << path[length] << endl;
}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	searchBFS(input.second, input.first);

	return 0;
}