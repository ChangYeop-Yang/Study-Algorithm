#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define HOME 1
#define CHICKEN 2
#define OPEN 3

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

// 임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.
const int calculateDistance(const INT_PAIR first, const INT_PAIR second) {
	return abs( (first.first + 1) - (second.first + 1) ) + abs( (first.second + 1) - (second.second + 1) );
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<INT_PAIR> chicken, home;
	vector<INT_VECTOR> map = vector<INT_VECTOR>(input.first, INT_VECTOR(input.first));

	for (int ii = 0; ii < input.first; ii++) {
		for (int jj = 0; jj < input.first; jj++) { 
			cin >> map[ii][jj]; 

			// 도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다.
			if (CHICKEN == map[ii][jj])		{ chicken.push_back(make_pair(ii, jj)); }
			else if (HOME == map[ii][jj])	{ home.push_back(make_pair(ii, jj)); }
		}
	}

	vector<short> maxChicken = vector<short>(chicken.size());
	for (int ii = 0; ii < input.second; ii++) { maxChicken[ii] = OPEN; }
	std::sort(maxChicken.begin(), maxChicken.end());

	int answer = INT_MAX;

	do {

		int sumDistance = 0;

		// 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.
		for (const auto homePos : home) {
			
			int minDistance = INT_MAX;
			for (int ii = 0; ii < chicken.size(); ii++) {
				if (maxChicken[ii] != OPEN) { continue; }

				const int distance = calculateDistance(homePos, chicken[ii]);
				minDistance = std::min(minDistance, distance);
			}

			sumDistance += minDistance;
		}

		// 도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다.
		answer = std::min(answer, sumDistance);

	} while ( next_permutation(maxChicken.begin(), maxChicken.end()) );

	cout << answer << endl;

	return 0;
}
