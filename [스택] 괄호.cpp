#include <iostream>
#include <cstring>
using namespace std;

/* STACK */
char STACK[52];
int TOP = -1;

/* STACK METHOD */
void PUSH(char mChar) { STACK[++TOP] = mChar; }
bool CHECK(char * mChar) 
{
	int R = 0, L = 0;
	int Len = strlen(mChar);
	
	for (int ii = 0; ii < Len; ii++)
	{ if (*(mChar + ii) == ')') { R++; } else { L++; } }

	return R != L ? true : false;
}

int main(void)
{
	char M[52];

	int N = 0, Len = 0;
	cin >> N;

	for (int count = 0; count < N; count++)
	{
		cin >> M;

		/* 시작이 ) 문자인 경우나 괄호의 갯수가 일치 하지 않은 경우 */
		if (M[0] == ')' || CHECK(M)) { cout << "NO" << endl; }
		else
		{
			Len = strlen(M);
			for (int jj = 0; jj < Len; jj++)
			{
				if (M[jj] == ')' && STACK[TOP] == '(') { STACK[(TOP)--] = 0; }
				else { PUSH(M[jj]); }
			}

			/* 결과 출력 */
			TOP == -1 ? cout << "YES" << endl : cout << "NO" << endl;

			/* 초기화 */
			memset(M, 0, sizeof(M));
			memset(STACK, 0, sizeof(STACK));
			TOP = -1;
		}
	}

	return 0;
}
