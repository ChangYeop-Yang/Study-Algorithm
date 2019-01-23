#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define PAIR pair<int, int>

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<PAIR> month = {make_pair(31, 1), make_pair(28, 4), make_pair(31, 4), make_pair(30, 0), make_pair(31, 2), make_pair(30, 5), make_pair(31, 0), make_pair(31, 3),
		make_pair(30, 6), make_pair(31, 1), make_pair(30, 4), make_pair(31, 6) };

	vector<string> day = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int index = month[input.first - 1].second;
	for (int ii = 1; ii < input.second; ii++) {
		index = (index + 1) % day.size();
	}

	cout << day[index] << endl;

	return 0;
}