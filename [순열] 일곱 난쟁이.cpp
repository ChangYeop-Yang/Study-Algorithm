#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> person = vector<int>(9);
	for (int ii = 0; ii < 9; ii++) {
		scanf_s("%d", &person[ii]);
	}
	
	vector<int> index = {0, 0, 0, 0, 0, 0, 0, 1, 1};
	do {

		set<int> answer;
		int sum = 0, location = 0;

		for (auto begin = index.begin(); begin != index.end(); begin++, location++) {

			if (*begin == 1) { continue; }

			answer.insert(person[location]);
			sum += person[location];
		}

		if (sum == 100) {
			for (auto begin = answer.begin(); begin != answer.end(); begin++) { cout << *begin << endl; }
		}

	} while ( next_permutation(index.begin(), index.end()) );

	return 0;
}
