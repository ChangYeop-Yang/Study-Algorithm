#include <iostream>
using namespace std;

int main(void)
{
	int N = 0, M = 0, J = 0;

	cin >> N >> M >> J;

	cout << (N + M) % J << endl;
	cout << (N % J + M % J) % J << endl;
	cout << (N * M) % J << endl;
	cout << (N % J * M % J) % J << endl;
	
	return 0;
}
