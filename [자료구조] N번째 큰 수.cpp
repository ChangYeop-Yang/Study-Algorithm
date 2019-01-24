#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
	int input = 0; cin >> input;
	
	PAIR inf = make_pair(0, input * input);
	
	for (int ii = 0; ii < inf.second; ii++) {
		scanf("%d", &inf.first);

		if (pq.size() < input) { pq.push(inf.first); } // Priority Queue에 N개 이하의 값이 들어있는 경우 추가한다.
	    else if (pq.top() < inf.first) { pq.pop(); pq.push(inf.first); } // Priority Queue에 N개 이상의 값이 있고 상위 값보다 큰 경우 변경한다.
	}

	// N번째의 큰수는 결국 N번째에서 가장 작은 수 이다. 그러므로 Priority Queue를 min-heap로 바꾸고 그 상단값을 계속 바꿔주면 정답니다.
	cout << pq.top() << endl;

	return 0;
}