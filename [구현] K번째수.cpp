#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int findTarget(const vector<int> & arr, const int left, const int right, const int target) {

	vector<int> bucket = vector<int>(arr.begin() + left, arr.begin() + right);
	std::sort(bucket.begin(), bucket.end());

	return bucket[target];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const auto command : commands) {
		const int number = findTarget(array, command[0] - 1, command[1], command[2] - 1);
		answer.push_back(number);
	}

	return answer;
}
