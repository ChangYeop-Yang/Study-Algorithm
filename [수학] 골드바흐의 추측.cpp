#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX 1000001

int pn = 0;
int check[MAX];
int prime[MAX];

/* Sieve of Eratoshenes */
void SoE() {

	for (long long ii = 2; ii <= MAX; ii++) {

		if (check[ii] == false) {
			prime[pn++] = ii;

			for (long long jj = ii * ii; jj <= MAX; jj += ii) {
				check[jj] = true;
			}
		}
	}
}

void even(int number) {

	for (int ii = 0; ii < pn; ii++) {
       
        int var = number - prime[ii];
		if (!check[var] && number == var + prime[ii]) {

			printf("%d = %d + %d\n", number, prime[ii], var);
			return;
		}
	}

	printf("Goldbach's conjecture is wrong.\n");
}

int main(void)
{
	SoE();

	while (true) {

		int number = 0;
		scanf("%d", &number);

		if (number <= 0) { break; }

		even(number);
	}

	return 0;
}