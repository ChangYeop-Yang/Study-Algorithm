#include <deque>
#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define PLUS 1
#define MINUS 2
#define MUL 3
#define DIV 4

#define LONG long long
#define LONG_PAIR pair<long long, long long>
#define PAIR pair<int, char>

vector<PAIR> operators = { make_pair(0, '+'), make_pair(0, '-'), make_pair(0, '*'), make_pair(0, '/') };

const vector<int> generation() {
	
	vector<int> permutation;
	for (int ii = 0; ii < operators.size(); ii++) {
		for (int jj = 0; jj < operators[ii].first; jj++) {
			switch (operators[ii].second) {
				case '+': permutation.push_back(1); break;
				case '-': permutation.push_back(2); break;
				case '*': permutation.push_back(3); break;
				case '/': permutation.push_back(4); break;
			}
		}
	}

	return permutation;
}

int main(void)
{
	int permutationNumber = 0;
	int digit = 0; cin >> digit;

	vector<int> bucket = vector<int>(digit);
	for (int ii = 0; ii < digit; ii++) { scanf("%d", &bucket[ii]); }
	for (int ii = 0; ii < operators.size(); ii++) { scanf("%d", &operators[ii].first); permutationNumber += operators[ii].first; }

	LONG_PAIR answer = make_pair(LLONG_MIN, LLONG_MAX); // <MAX, MIN>

	vector<int> permutation = generation();
	do {

		int index = 0;
		LONG temp = 0;
		vector<LONG> oper;
		deque<LONG> deq = deque<LONG>(bucket.begin(), bucket.end()); 

		while (!deq.empty()) {

			temp = deq.front(); deq.pop_front();
			oper.push_back(temp);

			if (oper.size() < 2) { continue; }

			switch (permutation[index++]) {
				case PLUS: deq.push_front(oper.front() + oper.back()); break;
				case MINUS: deq.push_front(oper.front() - oper.back()); break;
				case MUL: deq.push_front(oper.front() * oper.back()); break;
				case DIV: deq.push_front(oper.front() / oper.back()); break;
			}

			oper.clear();
		}

		answer.first = max(temp, answer.first);
		answer.second = min(temp, answer.second);

	} while ( next_permutation(permutation.begin(), permutation.end()) );

	cout << answer.first << endl << answer.second << endl;

	return 0;
}