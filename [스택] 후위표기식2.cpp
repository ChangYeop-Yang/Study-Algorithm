#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <stack>
using namespace std;

/* Typedef */
typedef struct tree * mTreePtr;

/* Struct */
typedef struct tree
{
	int mData;
	mTreePtr mLeft = NULL;
	mTreePtr mRight = NULL;
} Tree;

/* Function */
void MakeLeftSubTree(mTreePtr mTree, mTreePtr mSub)
{
	if (mTree->mLeft != NULL) { delete mTree->mLeft; }
	mTree->mLeft = mSub;
}
void MakeRightSubTree(mTreePtr mTree, mTreePtr mSub)
{
	if (mTree->mRight != NULL) { delete mTree->mRight; }
	mTree->mRight = mSub;
}
double EvaluateExpTree(mTreePtr mTree)
{
	double op1 = 0, op2 = 0;

	if ((mTree->mLeft == NULL) && (mTree->mRight == NULL)) /* 단말 노드일 경우 */
		return mTree->mData;

	op1 = EvaluateExpTree(mTree->mLeft);
	op2 = EvaluateExpTree(mTree->mRight);

	switch (mTree->mData)
	{
		case ('+') : { return op1 + op2; }
		case ('-') : { return op1 - op2; }
		case ('*') : { return op1 * op2; }
		case ('/') : { return op1 / op2; }
	}

	return 0;
}
mTreePtr MakeExpTree(string mString, map<char, int> mMap)
{
	/* Stack */
	stack<mTreePtr> mStack;

	/* Int */
	int mSize = mString.size();

	for (int ii = 0; ii < mSize; ii++)
	{
		/* Node */
		Tree * mTree = new Tree;

		/* 피연산자 */
		if ((mString[ii] >= 65) && (mString[ii] <= 90))
		{ mTree->mData = mMap[mString[ii]]; }
		/* 연산자 */
		else
		{
			MakeRightSubTree(mTree, mStack.top()); mStack.pop(); /* 스택의 첫번째 값이 오른쪽 노드 값 */ 
			MakeLeftSubTree(mTree, mStack.top()); mStack.pop(); /* 스택의 두번째 값이 왼쪽 노드 값 */
			mTree->mData = mString[ii]; /* 연산자 저장 */
		}

		mStack.push(mTree); /* 만들어진 연산 트리를 저장 */
	}

	return mStack.top(); /* 최종 연산 트리 반환 */
}

int main(void)
{
	/* int */
	int mNum = 0;
	cin >> mNum;

	/* String */
	string mString;
	cin >> mString;

	/* Map */
	map<char, int> mMap;

	for (int ii = 0, mTemp = 0; ii < mNum; ii++)
	{	
		cin >> mTemp;
		mMap.insert(make_pair((ii + 'A'), mTemp));
	}

	/* Tree */
	Tree * mTree = MakeExpTree(mString, mMap);
	
	printf("%.2f\n", EvaluateExpTree(mTree));
		
	return 0;
}
