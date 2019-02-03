#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int number = 0; cin >> number;

	vector<int> score = vector<int>(number);
	vector<int> step = vector<int>(number, 1);
	for (int ii = 0; ii < number; ii++) { cin >> score[ii]; }

	for (int ii = 0; ii < number; ii++) {
		for (int jj = ii; jj >= 0; jj--) {
			// S[ii]번째의 값이 S[jj]값보다 더 큰 경우
			if (score[ii] > score[jj]) { 
				step[ii] = max(step[ii], step[jj] + 1);
			}
		}
	}

	int answer = 0;
	for (const auto val : step) { answer = max(answer, val); }
	cout << answer << endl;

	return 0;
}