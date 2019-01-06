#include <vector>
#include <iostream>
using namespace std;

/* Sieve of Eratoshenes */
int SoE(int n, int m) {

	vector<int> nonPrime;
	vector<bool> check = vector<bool>(n + 1, true);

	for (long long ii = 2; ii <= n; ii++) {
		if (check.at(ii)) {
			nonPrime.push_back(ii);

			for (long long jj = ii * ii; jj <= n; jj += ii) {

				if (check.at(jj) == false) { continue; }

				check[jj] = false;
				nonPrime.push_back(jj);
			}
		}
	}

	return nonPrime.at(m - 1);
}

int main(void)
{
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;

	cout << SoE(num1, num2) << endl;

	return 0;
}
