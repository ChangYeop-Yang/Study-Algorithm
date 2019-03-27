#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const bool compare(const string & first, const string & second) {
	return first + second > second + first;
}

int main(void)
{
	int input = 0; cin >> input;

	vector<string> bucket = vector<string>(input);
	for (int ii = 0; ii < input; ii++) { cin >> bucket[ii]; }

	std::sort(bucket.begin(), bucket.end(), compare);

	string answer = string();
	for (const auto value : bucket) { answer += value; }

	cout << (std::atoi(answer.c_str()) == 0 ? "0" : answer) << endl;

	return 0;
}
