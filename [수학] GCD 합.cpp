#include <vector>
#include <iostream>
using namespace std;

/* Reculsive greatest Common Divisor - (logN) */
int GCD(int a, int b) {

	if (b == 0) { return a; }
	else { return GCD(b, a%b); }
}

int main(void)
{
	int testcase = 0;
	cin >> testcase;

	for (int ii = 0; ii < testcase; ii++) {
		int number = 0;
		cin >> number;

		long long sum = 0;
		vector<int> bucket = vector<int>(number, 0);
		for (int jj = 0, temp = 0; jj < number; jj++) {
			cin >> bucket[jj];
		}

		for (int kk = 0, length = bucket.size(); kk < length; kk++) {
			for (int qq = kk + 1; qq < length; qq++) {
				sum += GCD(bucket.at(kk), bucket.at(qq));
			}
		}

		cout << sum << endl;
	}

	return 0;
}