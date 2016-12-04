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
