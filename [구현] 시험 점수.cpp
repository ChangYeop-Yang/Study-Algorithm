#include <iostream>
#include <algorithm>
using namespace std;

#define LEN 4

int main(void)
{
	register pair<int, int> answer = make_pair(0, 0);
	for (int ii = 0, val = 0; ii < LEN; ii++) { cin >> val; answer.first += val; }
	for (int ii = 0, val = 0; ii < LEN; ii++) { cin >> val; answer.second += val; }

	if (answer.first == answer.second) { cout << answer.first << endl; }
	else { cout << max(answer.first, answer.second) << endl; }

	return 0;
}