#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define ENTER "enter"
#define EXIT "leave"
#define LEN 5
#define PAIR pair<char*, char*>

set<string> logs;

int main(void)
{
	int person = 0; cin >> person;
	PAIR input = make_pair(new char[LEN], new char[LEN]);

	for (int ii = 0; ii < person; ii++) {
		scanf("%s %s", input.first, input.second);

		if (logs.find(input.first) != logs.end()) {
			if (strcmp(input.second, EXIT) == 0) { logs.erase(input.first); }
			continue;
		}

		if (strcmp(input.second, ENTER) == 0) { logs.insert(input.first); }
	}

	vector<string> bucket = vector<string>(logs.size());
	copy(logs.begin(), logs.end(), bucket.begin());
	reverse(bucket.begin(), bucket.end());

	for (auto begin = bucket.begin(); begin != bucket.end(); begin++) {
		printf("%s\n", (*begin).c_str());
	}

	return 0;
}