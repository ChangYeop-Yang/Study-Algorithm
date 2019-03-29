#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define INT_PAIR pair<int, int>

const int findStudent(const int index, const unordered_set<int> & lost) {
	int answer = 0;
	if (lost.find(index - 1) != lost.end()) { answer++; } // MARK: - 작은 쪽 체구 가진 친구
	if (lost.find(index + 1) != lost.end()) { answer++; } // MARK: - 큰 체구 가진 친구
	return answer;
}

const bool compare(const INT_PAIR & first, const INT_PAIR & second) {
	return first.second < second.second;
}

int solution(int n, vector<int> lost, vector<int> reserve) {

	unordered_set<int> lostStudent = unordered_set<int>(lost.begin(), lost.end());
	
	vector<INT_PAIR> student;

	for (auto begin = reserve.begin(); begin != reserve.end(); begin++) {
        // MARK: - 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
		if (lostStudent.find(*begin) != lostStudent.end()) { lostStudent.erase(*begin); continue; }
		
        // MARK: - 여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
		const auto value = make_pair(*begin, findStudent(*begin, lostStudent));
		student.push_back(value);
	}
    
    // MARK: - 빌려줄 수 있는 친구의 수가 작은 수로 정렬
	std::sort(student.begin(), student.end(), compare);
	
	for (const auto value : student) {
		if (lostStudent.empty()) { continue; }
        // MARK: - 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다.
		if (lostStudent.find(value.first - 1) != lostStudent.end()) { lostStudent.erase(value.first - 1); }
		else if (lostStudent.find(value.first + 1) != lostStudent.end()) { lostStudent.erase(value.first + 1); }
	}
	
    // MARK: - 체육수업을 들을 수 있는 학생의 최댓값을 return
	return n - lostStudent.size();
}