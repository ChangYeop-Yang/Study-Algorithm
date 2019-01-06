#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int testcase = 0;
	while (true) {

		int number = 0;
		scanf_s("%d", &number);

		if (number <= 0) { break; }

		vector<int> bucket = vector<int>(number);
		
		vector<int> lotto;
		for (int ii = 0; ii < number - 6; ii++) { lotto.push_back(0); }
		for (int ii = 0; ii < 6; ii++) { lotto.push_back(1); }

		for (int ii = 0; ii < number; ii++) { scanf_s("%d", &bucket[ii]); }

		vector<vector<int> > printVec;
		do { printVec.push_back(lotto); } 
		while (next_permutation(lotto.begin(), lotto.end()));

		for (auto begin = printVec.rbegin(); begin != printVec.rend(); begin++) {
			
			int index = 0;
			for (auto innerBegin = (*begin).begin(); innerBegin != (*begin).end(); innerBegin++, index++) {
				if (*innerBegin <= 0) { continue; }
				printf("%d ", bucket.at(index));
			}

			printf("\n");
		}
		
		printf("\n");
	}

	return 0;
}