#include <vector>
#include <iostream>
using namespace std;

#define MAX_V 50
#define LONG long long

vector<LONG> answer = vector<LONG>(MAX_V, 1);

LONG factorial(int index) {

	if (index <= 1) { return 1; }

	// Memorization
	if (answer[index] > 1) { return answer[index]; }

	answer[index] = index * factorial(index - 1);

	return answer[index];
}

int main(void)
{
	int number = 0; cin >> number;

	factorial(number);

	cout << answer[number] << endl;

	return 0;
}