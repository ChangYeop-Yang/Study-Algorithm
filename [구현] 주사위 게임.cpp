#include <map>
#include <vector>
#include <iostream>
using namespace std;

#define LEN 3

int main(void)
{
	int person = 0; cin >> person;

	register int max = 0;
	for (int ii = 0; ii < person; ii++) {

		map<int, int> dice;
		vector<int> box = vector<int>(LEN);
		for (int jj = 0; jj < LEN; jj++) {
			cin >> box[jj];

			if ( dice.find(box[jj]) != dice.end() ) { dice[box[jj]]++; continue; }
			dice.insert(make_pair(box[jj], 1));
		}

		pair<int, int> type = make_pair(0, 0);
		for (auto begin = dice.begin(); begin != dice.end(); begin++) {
			if (type.second < (*begin).second) { type = *begin; }
		}

		int cost = 1;
		if (type.second == 3) { cost = 10000 + type.first * 1000; }
		else if (type.second == 2) { cost = 1000 + type.first * 100; }
		else { cost = (*dice.rbegin()).first * 100; }

		if (max < cost) max = cost;
	}

	cout << max << endl;

	return 0;
}