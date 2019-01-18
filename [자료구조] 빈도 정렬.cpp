#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

typedef struct element {
	int index = 0;
	int frequency = 0;
} Element;

map<int, Element> sorted;

bool compare(const pair<int, Element> comp1, const pair<int, Element> comp2) {
	if (comp1.second.frequency == comp2.second.frequency) { return comp1.second.index < comp2.second.index; }
	else { return comp1.second.frequency > comp2.second.frequency; }
}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	for (int ii = 0, number = 0; ii < input.first; ii++) {

		scanf("%d", &number);
		
		if (sorted.find(number) != sorted.end()) { sorted[number].frequency++; continue; }

		Element temp; temp.frequency = 1; temp.index = ii;
		sorted.insert(make_pair(number, temp));
	}

	vector<pair<int, Element> > answer = vector<pair<int, Element> >(sorted.begin(), sorted.end());
	sort(answer.begin(), answer.end(), compare);

	for (auto begin = answer.begin(); begin != answer.end(); begin++) {
		for (int ii = 0; ii < (*begin).second.frequency; ii++) { printf("%d ", *begin); }
	}

	return 0;
}