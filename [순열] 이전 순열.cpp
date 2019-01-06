#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

bool priviousPermutation(vector<int> arr, int n) {

	int temp = 0;

	/* 001. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다. */
	int ii = n - 1;
	while (ii > 0 && arr[ii] >= arr[ii - 1]) { ii--; }

	/* Last Permutation */
	if (ii <= 0) { cout << -1 << endl; return false; }

	/* 002. A[i-1] < A[j]를 만족하는 가장 큰 j를 찾는다. (j>=i) */
	int jj = n - 1;
	while (jj >= ii && arr[jj] >= arr[ii - 1]) { jj--; }
	SWAP(arr[ii - 1], arr[jj], temp);

	for (int tt = n - 1; ii < tt; tt--, ii++) {
		SWAP(arr[ii], arr[tt], temp);
	}
	
	for (auto begin = arr.begin(); begin != arr.end(); begin++) {
		cout << *begin << " ";
	}

	cout << endl;
	return true;
}

int main(void)
{
	int permutation = 0;
	cin >> permutation;

	vector<int> bucket = vector<int>(permutation);

	for (int ii = 0; ii < permutation; ii++) {
		cin >> bucket[ii];
	}

	priviousPermutation(bucket, bucket.size());

	return 0;
}