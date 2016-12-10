#include <iostream>
using namespace std;

int main(void)
{
	long long int N = 0, M = 0, sum = 0;

	cin >> N >> M;
	sum = N - M;

	if (sum <= 0) { sum *= -1; }

	cout << sum << endl;
	
	return 0;
}
