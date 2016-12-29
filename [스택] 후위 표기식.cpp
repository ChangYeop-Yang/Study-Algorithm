#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Function */
short GetOpPrec(char mChar) /* 연산자의 연산 우선순위 정보를 반환한다. */
{
	/* Short */
	short mShort = 0;

	switch (mChar)
	{
		case ('+') : {}
		case ('-') : { mShort = 2; break; }
		case ('*') : {}
		case ('/') : { mShort = 3; break; }
		case ('(') : { mShort = 1;  break; }
	}

	return mShort;
}
short WhoPrecOp(char mChar1, char mChar2)
{
	short mOP1 = GetOpPrec(mChar1);
	short mOP2 = GetOpPrec(mChar2);

	if (mOP1 > mOP2) { return 1; }
	else if (mOP1 < mOP2) { return -1; }
	else { return 0; }
}
void Convert(string mString)
{
	/* String */
	string mTemp;

	/* Stack */
	stack<char> mStack;

	int mSize = mString.size();
	for (int ii = 0; mSize > ii; ii++)
	{
		/* Char */
		char mChar = mString[ii];
		if ((mChar >= 65) && (mChar <= 90)) { mTemp.push_back(mChar); continue; } /* 피연산자는 그냥 옮긴다. */
		else /* 연산자는 Stack에 저장한다. */
		{
			if ((mChar != ')') && (mStack.empty())) { mStack.push(mChar); continue; } /* ')' 괄호 연산자가 아니고 스택이 비어있는 경우는 바로 저장한다. */
			else
			{
				switch (mChar)
				{
					case ('(') : { mStack.push(mChar); break; }
					case (')') : 
					{
						/* ')' 연산자 */
						for (; true; mStack.pop())
						{
							if (mStack.top() != '(') { mTemp.push_back(mStack.top()); } else { mStack.pop(); break; }
						}

						break; 
					}
					case ('+') : case ('-') : 
					case ('*') : case ('/') :
					{
						/* 그 외 연산자 */
						while (!mStack.empty() && WhoPrecOp(mStack.top(), mChar) >= 0)
						{ mTemp.push_back(mStack.top()); mStack.pop(); }

						mStack.push(mChar); /* 높은 값의 연산자를 저장한다. */
					}
				}
			}
		}
	}

	for (; !mStack.empty(); mStack.pop())
		mTemp.push_back(mStack.top());

	cout << mTemp << endl;
}

int main(void)
{
	string mString;
	cin >> mString;

	Convert(mString);

	return 0;
}
