#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<int> arr)
{
	bool answer = true;
	int currnt	= 1;

	sort(arr.begin(), arr.end());
	for (const int number : arr) {
		if (currnt++ != number) { answer = false; break; }
	}

	return answer;
}
