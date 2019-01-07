#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

void sum(int index, int sumVal, const int goal, const vector<int> bucket) {

	if (sumVal == goal && index == bucket.size()) { answer++; return; }
	if (index == bucket.size() && sumVal != goal) { return; }

	sum(index + 1, sumVal + bucket[index], goal, bucket);
	sum(index + 1, sumVal, goal, bucket);
}

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> bucket = vector<int>(input.first);
	for (int ii = 0; ii < input.first; ii++) {
		cin >> bucket[ii];
	}

	sum(0, 0, input.second, bucket);
	
	if (input.second == 0) { answer--; }
	cout << answer << endl;

	return 0;
}