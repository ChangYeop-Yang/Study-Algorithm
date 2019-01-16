#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int number = 0;
	scanf("%d", &number);

	priority_queue<int> que;
	for (int ii = 0; ii < number; ii++) {
		
		int temp = 0; 
		scanf("%d", &temp);
		
		if (temp == 0) {
			if (que.empty()) { printf("0\n"); continue; }
			printf("%d\n", -que.top());
			que.pop();
			continue;
		}

		que.push(-temp);
	}

	return 0;
}