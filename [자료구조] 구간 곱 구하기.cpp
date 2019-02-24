#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007
#define LONG long long
#define INT_PAIR pair<int, int>

/* Segment Tree: 저장 된 자료들을 적절히 전처리하여 그들에 대한 질의들을 빠르게 대답할 수 있는 트리 */
typedef struct RMQ {

	int length = 0; // 배열의 길이를 저장하는 변수

	vector<LONG> rangeMin; // 각 구간의 최소치를 저장하는 배열

	RMQ(const vector<LONG> & arr) {
		this->length = arr.size();
		this->rangeMin.resize(this->length * 4);
		this->init(arr, 0, length - 1, 1);
	}

	// Node 노드가 Array[left..right] 배열을 표현할 때, Node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다.
	const LONG init(const vector<LONG> & arr, int left, int right, int node) {
		/* 현재 구간을 두 개로 나누어 재귀 호출한 뒤, 두 구간의 최소치 중 더 작은 값을 선택하여 해당 구간의 최소치를 계산한다. */

		/* 터미널 노드 (Leaf node, a node of a tree data structure that has no child nodes.)일 경우 */
		if (left == right) { return (this->rangeMin[node] = arr[left]); }

		const int mid = (left + right) / 2;
		return this->rangeMin[node] = (init(arr, left, mid, node * 2) * init(arr, mid + 1, right, node * 2 + 1)) % MOD; // Time Complxity - log(n)
	}

	private:
		// Node가 표현하는 범위 [NodeLeft, NodeRight]와 우리가 최소치를 찾기 원하는 구간 [left, right]의 교집합의 최소 원소를 반환한다.
		const LONG query(int left, int right, int node, int nodeLeft, int nodeRight) {

			// 두 구간이 겹치지 않으면 아주 큰 값을 반환한다. (교집합이 공집합인 경우)
			if (right < nodeLeft || nodeRight < left) { return 1; }

			// Node가 표현하는 범위 Array[nodeLeft, NodeRight]에 완전히 포함되는 경우
			if (left <= nodeLeft && nodeRight <= right) { return this->rangeMin[node]; }

			// 이 외의 모든 경우 (양쪽 구간을 나누어서 푼 뒤 결과를 합친다.)
			const int mid = (nodeLeft + nodeRight) / 2;
			return (query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight)) % MOD;
		} // 노드가 표현하는 구간이 찾고자하는 구간에 완전히 포함되거나 아예 겹쳐지지 않는 경우에는 탐색을 종료한다.

		// Array[Index] = newValue로 바뀌었을 때 node를 루트로 하는 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
		const LONG update(int index, LONG newValue, int node, int nodeLeft, int nodeRight) {

			// Index가 노드가 표현하는 구간과 상관이 없는 경우
			if (index < nodeLeft || index > nodeRight) { return this->rangeMin[node]; }

			/* 터미널 노드 (Leaf node, a node of a tree data structure that has no child nodes.)일 경우 */
			if (nodeLeft == nodeRight) { return this->rangeMin[node] = newValue; }

			const int mid = (nodeLeft + nodeRight) / 2;
			return rangeMin[node] = (update(index, newValue, node * 2, nodeLeft, mid) * update(index, newValue, node * 2 + 1, mid + 1, nodeRight)) % MOD;
		}

	public:
		const LONG query(int left, int right) { return this->query(left, right, 1, 0, length - 1); } // Time Complxity - log(n)
		const LONG update(int index, LONG newValue) { return this->update(index, newValue, 1, 0, length - 1); }
} RMQ;

int main(void)
{
	vector<int> input = { 0, 0, 0 }; 
	cin >> input[0] >> input[1] >> input[2];

	vector<LONG> board = vector<LONG>(input[0]);
	for (int ii = 0; ii < input[0]; ii++) { cin >> board[ii]; }

	RMQ segment = RMQ(board);
	for (int ii = 0; ii < input[1] + input[2]; ii++) {
		LONG mode = 0, value1 = 0, value2 = 0;
		cin >> mode >> value1 >> value2;

		if (mode == 1) { segment.update(value1 - 1, value2); }
		else { cout << segment.query(value1 - 1, value2 - 1) << endl; }
	}

	return 0;
}
