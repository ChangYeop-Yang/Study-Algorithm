#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string mString1;
	string mString2;

	cin >> mString1;
	
	int mSize = mString1.size() - 1;
	for (int ii = mSize; ii >= 0; ii--)
	{ mString2.push_back(mString1[ii]); }

	cout << (mString1.compare(mString2) == 0 ? 1 : 0) << endl;

	return 0;
}

/* KMP 방식 */
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

const vector<int> getPartialMatch(const string & first) {

	// MARK: - KMP를 통해 자기 자신을 찾는다. N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니 안됨을 주의한다.
	int m = first.size(), begin = 1, mached = 0;

	vector<int> pi(m, 0);
	// MARK: - 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + mached < m) {
		if (first[begin + mached] == first[mached]) { ++mached; pi[begin + mached - 1] = mached; }
		else {
			if (mached == 0) { ++begin; } // 찾고자 한 문자열이 아닌 경우 시작점을 바꾸어 준다.
			else { begin += mached - pi[mached - 1]; mached = pi[mached - 1]; }
		}
	}

	return pi;
}

const vector<int> kmpSearch(const string & first, const string & second) {

	const int n = first.size(), m = second.size();

	vector<int> ret, pi = getPartialMatch(second);

	// MARK: - 현재 대응 된 글자의 수의 값을 저장하는 변수
	int begin = 0, matched = 0;

	while (begin <= n - m) {
		// Case 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같은 경우
		if (matched < m && first[begin + matched] == second[matched]) {
			matched++;
			// MARK: - 모든 문자가 찾고자 하는 문자열에 대응 되는 경우
			if (matched == m) { ret.push_back(begin); }
		}
		else {
			// MARK: - matched가 0인 경우에는 다음 칸에서 부터 계속한다.
			if (matched == 0) { ++begin; }
			else {
				begin += matched - pi[matched - 1];
				// MARK: - begin을 옮겼다고 처음부터 다시 비교할 필요는 없다. 옮긴 후에도 pi[matched - 1]만큼은 항상 일치한다.
				matched = pi[matched - 1];
			}
		}
	}

	return ret;
}

int main(void)
{
	pair<string, string> input = make_pair(string(), string());
	std::getline(cin, input.first);

	input.second = input.first;
	std::reverse(input.second.begin(), input.second.end());

	cout << !kmpSearch(input.second, input.first).empty() << endl;

	return 0;
}
