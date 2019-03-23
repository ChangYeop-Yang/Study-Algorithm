#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

#define STRING_VECTOR vector<string>
#define STRING_PAIR pair<string, string>

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {

		int input = 0; cin >> input;

		unordered_map<string, STRING_VECTOR> wardrobe;
		for (int ii = 0; ii < input; ii++) {
			STRING_PAIR clothes = make_pair(string(), string());
			cin >> clothes.first >> clothes.second;
			
			// Case Not Contain Wardrobe.
			if (wardrobe.find(clothes.second) == wardrobe.end()) { 
				const auto item = make_pair(clothes.second, STRING_VECTOR());
				wardrobe.insert(item);
			}

			wardrobe[clothes.second].push_back(clothes.first);
		}

		int answer = 1;
		for (auto begin = wardrobe.begin(); begin != wardrobe.end(); begin++) {
			const auto temp = *begin;
			answer *= (temp.second.size() + 1);
		}

		/* ※ Soluction	
			각각 종류마다 n1,n2,n3 가지고 있다면 (n1) x (n2) x (n3) 이다.
			하지만 문제에서 제시 된 각각 종류를 입지 않는 경우도 있으므로 경우의 수 +1 하게되면
			(n1 + 1) x (n2 + 1) x (n3 + 1) 의 식이된다.
			그리고 이후 마지막에는 모두 입지 않은 경우의수 -1 를 하게되면 답이 나오게 된다.
		*/

		cout << answer - 1 << endl;
	}

	return 0;
}