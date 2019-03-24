#include <vector>
#include <climits>
#include <iostream>
using namespace std;

#define ROOT 0
#define MAX_N 10001

vector<int> binaryTree = vector<int>(MAX_N, EOF);

void convertPreOrderToPostOrder(int left, int right) {

	// Case Empty Binary Tree.
	if (left > right) { return; }

	const int root = left;
	int mleft = left, mright = right;

	while (binaryTree[mleft] >= binaryTree[root]) { mleft++; }
	while (binaryTree[mright] > binaryTree[root]) { mright--; }

	convertPreOrderToPostOrder(mleft, mright);
	convertPreOrderToPostOrder(mright + 1, right);

	cout << binaryTree[root] << endl;
}

int main(void)
{
	int input = 0;
	int index = 0;

	while (cin >> input) { binaryTree[index++] = input; }
	convertPreOrderToPostOrder(ROOT, index - 1);

	return 0;
}
