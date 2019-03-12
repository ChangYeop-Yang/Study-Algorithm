#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
	a : 배열변수
	tree : 세그먼트 트리
	node : 세그먼트 트리 노드 번호
	node가 담당하는 합의 범위 start ~ end
*/
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
	/* 잎노드 (리프노드) 인 경우 */
	if (start == end) { return tree[node] = a[start]; }
	else { return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end); }
	/* Node * 2 왼쪽 자식 / Node * 2 + 1 오른쪽 자식 */
}

/* Node가 담당하는 구간이 start-end이고, 구해야하는 합의 범위는 laft~right */
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	/* Node가 담당하는 구간와 구하고자 하는 합의 범위가 겹치지 않는 경우 */
	if (left > end || right < start) { return 0; }
	/* 구하고자하는 합의 범위가 Node가 담당하는 구간에 완전히 포함하는 경우 */
	if (left <= start && end <= right) { return tree[node]; }
	/* Node가 담당하는 구간에 구하고자하는 합의 범위가 완전히 포함하는 경우 및 겹쳐있는 경우 */
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	/* Node가 담당하는 구간에 index 값이 포함되지 않는 경우 */
	if (index < start || index > end) { return; }
	
	/* Node가 담당하는 구간에 index 값이 포함되는 경우 */
	tree[node] = tree[node] + diff;
	if (start != end) /* 잎 노드가 아닌 경우 */
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff); /* Left Node 변경 */
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff); /* Right Node 변경 */
	}

}

int main(void)
{
	int mNum[3] = { 0, 0, 0 };
	cin >> mNum[0] >> mNum[1] >> mNum[2];

	vector<long long> a(mNum[0]);
	
	/* Tree 크기 결정 */
	int h = (int)ceil(log2(mNum[0]));
	int tree_size = (1 << (h+1));
	vector<long long> tree(tree_size);

	mNum[1] += mNum[2];

	for (int ii = 0; ii < mNum[0]; ii++)
	{ cin >> a[ii]; }

	init(a, tree, 1, 0, mNum[0] - 1);
	while (mNum[1]--)
	{
		int mTemp = 0;
		cin >> mTemp;

		switch (mTemp)
		{
			case (1) : 
			{
				int ii = 0;
				long long jj = 0;
				cin >> ii >> jj;

				long long diff = jj - a[--ii];
				a[ii] = jj;
				update(tree, 1, 0, mNum[0] - 1, ii, diff);

				break; 
			}
			case (2) : 
			{ 
				int ii, jj = 0;
				cin >> ii >> jj;

				cout << sum(tree, 1, 0, mNum[0] - 1, ii-1, jj-1) << endl;
				break; 
			}
		}

	}

	return 0;
}

// FENWICK Tree 방법
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define LONG long long
#define INT_PAIR pair<int, int>
#define DIV 1000000007

/* 가상의 배열 A[]의 부분 합을 빠르게 구현할 수 있도록 한다. 초기화시에는 A[]의 원소가 전부 0이라 생각한다. */
typedef struct FenwickTree {

private:
	vector<LONG> tree;

public:
	FenwickTree(int n) :tree(n + 1) {}

	// A[0..pos]까지의 부분합을 구한다.
	const LONG sum (int pos) {
		LONG ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos -= (pos & -pos); // 다음 구간을 찾기 위하여 최종 비트를 지운다.
		}
		return ret;
	}

	// 펜윅 트리 갱신 : A[pos]에 Value를 더한다.
	void update (int pos, LONG val) {
		while (pos <= this->tree.size()) { this->tree[pos] += val; pos += (pos & -pos); }
	}

} FENWICK;

int main(void)
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;

	FenwickTree fenw = FenwickTree(n + 1);
	vector<LONG> board = vector<LONG>(n + 1);
	for (int ii = 1; ii <= n; ii++) { cin >> board[ii]; fenw.update(ii, board[ii]); }

	for (int ii = 0; ii < m + k; ii++) {

		LONG q = 0, w = 0, r = 0;
		cin >> q >> w >> r;

		if (q == 1) {
			fenw.update(w, r - board[w]);
			board[w] = r;
		}
		else { cout << fenw.sum(r) - fenw.sum(w - 1) << endl; }
	}

	return 0;
}
