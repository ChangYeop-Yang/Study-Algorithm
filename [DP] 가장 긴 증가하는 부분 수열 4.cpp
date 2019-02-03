#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int number, const vector<int> index, const vector<int> score) {
	if (number == EOF) { return; }
	print(index[number], index, score);

	cout << score[number] << " ";
}

int main(void)
{
	int number = 0; cin >> number;

	vector<int> score = vector<int>(number);
	vector<int> step = vector<int>(number, 1);
	vector<int> answer = vector<int>(number, EOF);
	for (int ii = 0; ii < number; ii++) { cin >> score[ii]; }

	for (int ii = 0; ii < number; ii++) {
		for (int jj = ii; jj >= 0; jj--) {
			if (score[ii] > score[jj] && step[ii] < step[jj] + 1) {
				step[ii] = step[jj] + 1;
				// 증가하는 배열의 Index 값 저장
				answer[ii] = jj;
			}
		}
	}

	pair<int, int> maxVal = make_pair(0, 0);
	for (int ii = 0; ii < number; ii++) { if (maxVal.first < step[ii]) { maxVal.first = step[ii]; maxVal.second = ii; } }

	cout << step[maxVal.second] << endl;
	print(maxVal.second, answer, score);

	return 0;
}