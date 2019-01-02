#include <vector>
using namespace std;

long long solution(int N) {
	long long answer = 0;

	vector<long long> prime;
	vector<bool> check = vector<bool>(N + 1, false);

	for (long long ii = 2; ii <= N; ii++) {

		if (check.at(ii) == false) {
			prime.push_back(ii);

			for (long long jj = ii * ii; jj <= N; jj += ii) {
				check[jj] = true;
			}
		}
	}

	for (auto begin = prime.begin(); begin != prime.end(); begin++) {
		answer += *begin;
	}

	return answer;
}