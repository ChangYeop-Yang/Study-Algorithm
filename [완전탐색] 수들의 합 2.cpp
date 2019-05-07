#include <vector>
#include <iostream>
using namespace std;

#define INT_PAIR pair<int, int>

int main(void)
{
	// MARK: - N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.
	int number = 0, target = 0; cin >> number >> target;

	vector<int> permutation = vector<int>(number);
	for (int ii = 0; ii < number; ii++) { cin >> permutation[ii]; }

	// MARK: - Left, Right
	INT_PAIR pos = make_pair(0, 0);
	int answer = 0, sum = permutation.front();

	while (pos.first <= pos.second && pos.second < number) {

		// MARK: - Right가 증가는 합이 커지는 경우이고 Left가 감소하는 경우는 합이 작아지는 경우이다.
		if (target > sum) { sum += permutation[++pos.second]; }
		else if (target == sum) { sum += permutation[++pos.second]; answer++; }
		else if (target < sum) { 
			sum -= permutation[pos.first++]; 
			// MARK: - Left가 Right의 크기를 넘어선 경우에는 LEFT의 값을 RIGHT의 값으로 바꾸어 준다.
			if (pos.first > pos.second && pos.first < number) {
				pos.second = pos.first;
				sum = permutation[pos.first];
			}
		}
	}

	cout << answer << endl;

	return 0;
}
