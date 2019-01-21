#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int person = 0; cin >> person;

	vector<int> wating = vector<int>(person);
	for (int ii = 0; ii < person; ii++) { scanf("%d", &wating[ii]); }
	sort(wating.begin(), wating.end());

	int answer = wating[0];
	for (int ii = 1; ii < person; ii++) {
		wating[ii] = wating[ii - 1] + wating[ii];
		answer += wating[ii];
	}

	cout << answer << endl;

	return 0;
}