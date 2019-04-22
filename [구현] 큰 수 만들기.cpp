#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {

	string bucket;
	vector<int> removeAt;

	// MARK: - 주어진 숫자로부터 하나씩 꺼내어 모으면서, 이때 모아둔 것 중 지금 등장한 것보다 작은 것들을 빼낸다.
	for (const auto letter : number) {
		// MARK: - 현재 조합하고자 하는 배열이 비어있는 경우
		if (bucket.empty()) { bucket.push_back(letter); continue; }

		// MARK: - 현재의 숫자들이 추가 될 숫자보다 작은 경우에는 제거한다.
		while (!bucket.empty() && removeAt.size() != k && bucket.back() < letter) {
			removeAt.push_back(bucket.back()); bucket.pop_back();
		}
		
		bucket.push_back(letter);
	}

	// MARK: - 내림차순으로 정렬이 되어있는 경우에는 끝의 K만큼 제거한다.
	string answer = removeAt.empty() ? number.substr(0, number.size() - k) : bucket;
	return answer;
}
