#include <map>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

bool checkBitmask(const int number, const int target) {
	int bit = (1 << target);
	return (number & bit) != 0;
}

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	int answer = 0;

	for (int ii = 0; ii < input; ii++) {

		pair<string, int> commend = make_pair(string(), 0);
		
		char temp[20];
		scanf("%s", temp);
		
		commend.first = string(temp);

		// ADD
		if (commend.first.compare("add") == 0) { 
			scanf("%d", &commend.second);
			if (checkBitmask(answer, commend.second)) { continue; }
			answer |= (1 << commend.second);
		// REMOVE
		} else if (commend.first.compare("remove") == 0) {
			scanf("%d", &commend.second);
			if (!checkBitmask(answer, commend.second)) { continue; }
			answer ^= (1 << commend.second);
		// CHECK
		} else if (commend.first.compare("check") == 0) {
			scanf("%d", &commend.second);
			printf("%d\n", checkBitmask(answer, commend.second));
		// TOGGLE
		} else if (commend.first.compare("toggle") == 0) {
			scanf("%d", &commend.second);
			if (checkBitmask(answer, commend.second)) { answer ^= (1 << commend.second); continue; }
			answer |= (1 << commend.second);
		// ALL
		} else if (commend.first.compare("all") == 0) {
			for (int ii = 1; ii <= 20; ii++) { answer |= (1 << ii); }
		// EMPTY
		} else if (commend.first.compare("empty") == 0) { answer = 0; }
	}

	return 0;
}